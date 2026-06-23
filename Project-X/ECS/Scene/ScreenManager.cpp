#include "ScreenManager.h"
#include "../../Main/GameEngine.h"
#include "../Tool/TimerComponent.h"
#include "../../Reader/SceneReader.h"

ScreenManager::ScreenManager(Object* _owner, Scene* scene) : Component(_owner), currentScene(scene) {
}

void ScreenManager::setScreen(std::string name) {
    currentScene->setState(Scene::State::Paused);
    GameEngine::getWindow()->setMouseCursorVisible(true);
    if (currentScene->getObjectsScreen() != nullptr) {
        currentScene->getPreviousScreen().push_back(currentScene->getObjectsScreen());
    }   
    currentScene->setScreen(name);
}

Scene* ScreenManager::getCurrentScene() {
    return currentScene;
}




