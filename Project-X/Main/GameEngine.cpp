#include "GameEngine.h"

sf::RenderWindow* GameEngine::window = nullptr;
std::unordered_map<int, Scene*> GameEngine::scenes;
std::unordered_map<int, Scene*> GameEngine::scenesPaused;
int GameEngine::idScene = 0;
int GameEngine::idScenePaused = 0;

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
    // SceneReader readScene;
    // readScene.SceneTestDev();
    //readScene.SceneTestDev2();
    //#############//
    readers.push_back(new InputReader());
    readers.push_back(new WeaponReader());
    readers.push_back(new SceneReader());
}

void GameEngine::readData() {
    for (auto& r : readers) {
        r->read();
    }
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
    if (scenes.count(idScene)) {
        if (!scenes[idScene]->getIsPaused()) {
            scenes[idScene]->update(delatTime);
        }
    }
    if (scenesPaused.count(idScenePaused)) {
        if (scenes[idScene]->getIsPaused()) {
            scenesPaused[idScenePaused]->update(delatTime);
        }
    }
}

void GameEngine::render() {
    if (scenes.count(idScene)) {
        scenes[idScene]->render();
    }
    if (scenesPaused.count(idScenePaused)) {
        if (scenes[idScene]->getIsPaused()) {
            scenesPaused[idScenePaused]->render();
        }
    }
}


sf::RenderWindow* GameEngine::getWindow() {
    return window;
}

std::unordered_map<int, Scene*>& GameEngine::getVecState() {
    return scenes;
}

std::unordered_map<int, Scene*>& GameEngine::getVecPaused() {
    return scenesPaused;
}

void GameEngine::setScene(int newScene) {
    idScene = newScene;
}

void GameEngine::setScenePaused(int newScene) {
    idScenePaused = newScene;
}

int GameEngine::getIdCurrentScenePaused() {
    return idScenePaused;
}

int GameEngine::getIdCurrentScene() {
    return idScene;
}


void GameEngine::run() {
    initRead();
    readData();
    
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
