#include "ScreenManager.h"
#include "../../Main/GameEngine.h"
#include "../Tool/TimerComponent.h"
#include "../../Reader/SceneReader.h"

ScreenManager::ScreenManager(Object* _owner, Scene* scene) : 
Component(_owner), hasEnd(false), death(false), currentScene(scene) {
}

void ScreenManager::state() {
    auto cam = owner->getComponent<CameraComponent>();
    
    GameEngine::getWindow()->setView(GameEngine::getWindow()->getDefaultView());
    
    if (death) {
        SceneReader::getScenes()["death"]->render();
    }
    else if (hasEnd) {
        SceneReader::getScenes()["win"]->render();
    }
    
    if (cam != nullptr) {
        GameEngine::getWindow()->setView(*cam->view);
    }
    
    GameEngine::getWindow()->setMouseCursorVisible(true);
}

void ScreenManager::update(float deltaTime) {
    auto health = owner->getComponent<HealthComponent>()->getHp();
    auto timer = owner->getComponent<TimerComponent>()->timer - owner->getComponent<TimerComponent>()->actualTime;
    
    if (health <= 0 ) {
        death = true;
        currentScene->setPaused((true));
    }
    else if (timer <= 0) {
        hasEnd = true;
        currentScene->setPaused((true));
    }
    
    if (death) {
        SceneReader::getScenes()["death"]->update(deltaTime);        
    }
    else if ((hasEnd)) {
        SceneReader::getScenes()["win"]->update(deltaTime);
    }
}

