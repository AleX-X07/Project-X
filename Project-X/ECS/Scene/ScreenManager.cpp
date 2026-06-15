#include "ScreenManager.h"
#include "../../Main/GameEngine.h"
#include "../Tool/TimerComponent.h"
#include "../../Reader/SceneReader.h"

ScreenManager::ScreenManager(Object* _owner, Scene* scene) : ScreenManager(_owner, scene, "", "", "", "") {
}

ScreenManager::ScreenManager(Object* _owner, Scene* _scene, std::string _nameWin, std::string _nameDeath,
    std::string _namePaused, std::string _nameSettings) : Component(_owner), currentScene(_scene), nameWin(_nameWin), nameDeath(_nameDeath), namePaused(_namePaused), nameSettings(_nameSettings) {
}

void ScreenManager::setScreen(std::string name) {
    currentScene->setState(Scene::State::Paused);
    GameEngine::getWindow()->setMouseCursorVisible(true);
    currentScene->setScreen(name);
}

void ScreenManager::update(float deltaTime) {
    auto health = owner->getComponent<HealthComponent>()->getHp();
    auto timer = owner->getComponent<TimerComponent>()->timer - owner->getComponent<TimerComponent>()->actualTime;
    
    
    if (health <= 0 ) {
        setScreen(nameDeath);
    }
    else if (timer <= 0) {
        setScreen(nameWin);    
    }
    else if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Pause"))) {
        setScreen(namePaused);
    }
}

