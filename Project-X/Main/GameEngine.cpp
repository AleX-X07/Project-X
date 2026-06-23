#include "GameEngine.h"

sf::RenderWindow* GameEngine::window = nullptr;
std::unordered_map<int, std::string> GameEngine::scenes;
Scene* GameEngine::currentScene;
int GameEngine::idScene = 0;
int GameEngine::nextScene = 0;

GameEngine::GameEngine() {
    window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Project-X");
    delatTime = 0;
    idScene = 0;
    nextScene = -1;
    inGame = true;
}

GameEngine::~GameEngine() {
    delete window;
    window = nullptr;
}

void GameEngine::initRead() {    
    //## for dev ##//
    //InputReader input;
    //input.read();
    //WeaponReader weapons;
    //weapons.read();
    //SceneReader readScene;
    //readScene.SceneTestDev();
    // readScene.SceneTestDev2();
    // #############//
    SceneReader::getInstance()->read();
    currentScene = SceneReader::getInstance()->initScene(0);
}

void GameEngine::updateChangeScene() {
    if (nextScene == -1) {
        return;
    }
    if (idScene == nextScene) {
        nextScene = -1;
        return;
    }
    idScene = nextScene;
    window->setView(window->getDefaultView());
    delete currentScene;
    currentScene = nullptr;
    currentScene = SceneReader::getInstance()->initScene(idScene);
}

void GameEngine::updateEvent() {
    Input::getInput()->reset();
    while (const std::optional event = window->pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window->close();
        }
        if (event->is<sf::Event::FocusLost>()) {
            inGame = false;
        }
        if (event->is<sf::Event::FocusGained>()) {
            inGame = true;
        }
        Input::getInput()->setEvent(*event);
    }
}

void GameEngine::updateTime() {
    sf::Time elapsed = clock.getElapsedTime();
    clock.restart();
    delatTime = elapsed.asSeconds();
}

void GameEngine::update() {
    currentScene->update(delatTime);
}

void GameEngine::render() {
    currentScene->render();
}


sf::RenderWindow* GameEngine::getWindow() {
    return window;
}

std::unordered_map<int, std::string>& GameEngine::getMapScene() {
    return scenes;
}

void GameEngine::setScene(int newScene) {
    nextScene = newScene;
}

Scene* GameEngine::getCurrentScene() {  
    return currentScene;
}


void GameEngine::run() {
    initRead();
    
    while (window->isOpen()) {
        updateEvent();
        if (inGame) {
            updateChangeScene();
            updateTime();
            update();
            window->clear();
            render();
            window->display();  
        }
    }
}
