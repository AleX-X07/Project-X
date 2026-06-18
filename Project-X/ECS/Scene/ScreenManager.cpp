#include "ScreenManager.h"
#include "../../Main/GameEngine.h"
#include "../Tool/TimerComponent.h"
#include "../../Reader/SceneReader.h"

ScreenManager::ScreenManager(Object* _owner, Scene* scene) : Component(_owner), currentScene(scene),screenSet(false) {
}

void ScreenManager::setScreen(std::string name) {
    if (screenSet) return;
    screenSet = true;
        
    currentScene->setState(Scene::State::Paused);
    GameEngine::getWindow()->setMouseCursorVisible(true);
    previousScreen.push_back(currentScene->getObjectsScreen());
    currentScene->setScreen(name);
}

Scene* ScreenManager::getCurrentScene() {
    return currentScene;
}

std::vector<std::vector<Object*>*>& ScreenManager::getPreviousScreen() {
    return previousScreen;
}

void ScreenManager::resetScreenSet() {
    screenSet = false;
}



