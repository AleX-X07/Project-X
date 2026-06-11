#include "ScreenManager.h"
#include "../../Main/GameEngine.h"
#include "../Tool/TimerComponent.h"
#include "../../Reader/SceneReader.h"

ScreenManager::ScreenManager(Object* _owner, Scene* scene) : 
Component(_owner), hasEnd(false), death(false), currentScene(scene) {
}

void ScreenManager::update(float deltaTime) {
    auto health = owner->getComponent<HealthComponent>()->getHp();
    auto timer = owner->getComponent<TimerComponent>()->timer - owner->getComponent<TimerComponent>()->actualTime;
    
    if (health <= 0 ) {
        death = true;
        currentScene->setPaused((true));
        GameEngine::getWindow()->setMouseCursorVisible(true);
        GameEngine::setScenePaused(1);
    }
    else if (timer <= 0) {
        hasEnd = true;
        currentScene->setPaused((true));
        GameEngine::getWindow()->setMouseCursorVisible(true);
        GameEngine::setScenePaused(2);     
    }
}

