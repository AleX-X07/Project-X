#include "GameEngine.h"

sf::RenderWindow* GameEngine::window = nullptr;
std::unordered_map<int, Scene*> GameEngine::scenes;
int GameEngine::idScene = 0;

GameEngine::GameEngine() {
    window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Project-X");
    delatTime = 0;
    idScene = 0;
    inGame = true;
}

GameEngine::~GameEngine() {
    delete window;
    window = nullptr;
}

void GameEngine::initRead() {    
    //## for dev ##//
     InputReader input;
     input.read();
     WeaponReader weapons;
     weapons.read();
     SceneReader readScene;
     readScene.SceneTestDev();
    // readScene.SceneTestDev2();
    // #############//
    readers.push_back(new InputReader());
    readers.push_back(new WeaponReader());
    //readers.push_back(new SceneReader());
}

void GameEngine::readData() {
    for (auto& r : readers) {
        r->read();
    }
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
    if (scenes.count(idScene)) {
        scenes[idScene]->update(delatTime);
    }
}

void GameEngine::render() {
    if (scenes.count(idScene)) {
        scenes[idScene]->render();
    }
}


sf::RenderWindow* GameEngine::getWindow() {
    return window;
}

std::unordered_map<int, Scene*>& GameEngine::getVecState() {
    return scenes;
}

void GameEngine::setScene(int newScene) {
    idScene = newScene;
}

int GameEngine::getIdCurrentScene() {
    return idScene;
}


void GameEngine::run() {
    initRead();
    //readData();
    
    while (window->isOpen()) {
        updateEvent();
        if (inGame) {
            updateTime();
            update();
            window->clear();
            render();
            window->display();
        }    
    }
}
