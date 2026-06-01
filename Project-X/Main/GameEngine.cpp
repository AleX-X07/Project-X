#include "GameEngine.h"

sf::RenderWindow* GameEngine::window = nullptr;
std::vector<Scene*> GameEngine::scenes;
int GameEngine::idScene = 0;


GameEngine::GameEngine() {
    window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Project-X");
    delatTime = 0;
    idScene = 0;
}

GameEngine::~GameEngine() {
    delete window;
    window = nullptr;
}

void GameEngine::start() {
    SceneReader readScene;
    readScene.loadScene();
    
    //## for dev ##//
    //readScene.SceneTestDev();
    //#############//
    
    InputReader readInput;
    readInput.loadInput();
}

void GameEngine::updateEvent() {    
    while (const std::optional event = window->pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window->close();
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
        updateTime();
        update();
        window->clear();
        render();
        window->display();
    }
}
