#include "LevelEnder.h"
#include "../../Main/GameEngine.h"
#include "../Tool/TimerComponent.h"
#include "../../Reader/SceneReader.h"

LevelEnder::LevelEnder(Object* _owner, Scene* scene) : 
Component(_owner), hasEnd(false), death(false), currentScene(scene) {
}

void LevelEnder::update(float deltaTime) {
    auto health = owner->getComponent<HealthComponent>()->getHp();
    auto timer = owner->getComponent<TimerComponent>()->timer - owner->getComponent<TimerComponent>()->actualTime;
    
    if (health < 0 ) {
        death = true;
        currentScene->setPaused((true));
    }
    else if (timer < 0) {
        hasEnd = true;
        currentScene->setPaused((true));
    }
    
    if (death) {
        SceneReader::getScenes()["death"]->update(deltaTime);        
    }
    else if ((hasEnd)) {
        SceneReader::getScenes()["death"]->update(deltaTime);
    }
}

void LevelEnder::render() {
    if (death) {
        SceneReader::getScenes()["death"]->render();
    }
    else if (hasEnd) {
        SceneReader::getScenes()["win"]->render();
    }
}
