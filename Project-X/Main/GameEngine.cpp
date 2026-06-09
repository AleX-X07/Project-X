#include "GameEngine.h"

sf::RenderWindow* GameEngine::window = nullptr;
std::vector<Scene*> GameEngine::scenes;
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

void GameEngine::start() {    
    InputReader readInput;
    readInput.read();
    
    WeaponReader readWeapons;
    readWeapons.read();
    
    SceneReader readScene;
    readScene.read();
    
    //## for dev ##//
    //readScene.SceneTestDev();
    //readScene.SceneTestDev2();
    //#############//
}

void GameEngine::updateEvent() {    
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
    }
}

void GameEngine::updateTime() {
    sf::Time elapsed = clock.getElapsedTime();
    clock.restart();
    delatTime = elapsed.asSeconds();
}

void GameEngine::update() {
    if (!scenes.empty()) {
        scenes[idScene]->update(delatTime);
    }
}

void GameEngine::render() {
    if (!scenes.empty()) {
        scenes[idScene]->render();
    }
}


sf::RenderWindow* GameEngine::getWindow() {
    return window;
}

std::vector<Scene*>& GameEngine::getVecState() {
    return scenes;
}

void GameEngine::setScene(int newScene) {
    idScene = newScene;
}

int GameEngine::getIdCurrentScene() {
    return idScene;
}


void GameEngine::run() {
    start();
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
