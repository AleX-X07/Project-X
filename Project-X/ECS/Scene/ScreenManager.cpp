#include "ScreenManager.h"
#include "../../Main/GameEngine.h"
#include "../Tool/TimerComponent.h"
#include "../../Reader/SceneReader.h"

ScreenManager::ScreenManager(Object* _owner, Scene* scene, std::unordered_map<std::string, std::string> _screen) : Component(_owner), screen(std::move(_screen)), currentScene(scene) {
}

void ScreenManager::setScreen(std::string name) {
    currentScene->setState(Scene::State::Paused);
    GameEngine::getWindow()->setMouseCursorVisible(true);
    currentScene->setScreen(name);
}

void ScreenManager::update(float deltaTime) {
    // auto health = owner->getComponent<HealthComponent>()->getHp();
    // if (health <= 0 ) {
    //     currentScreen = "Death";
    // }
    // auto timer = owner->getComponent<TimerComponent>()->timer - owner->getComponent<TimerComponent>()->actualTime;
    // if (timer <= 0) {
    //     currentScreen = "Win";
    // }
    // if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Pause"))) {
    //     currentScreen = "Paused";
    // }
    // if (!currentScreen.empty() && screen.count(currentScreen)) {
    //     setScreen(screen[currentScreen]);
    // }
    auto health = owner->getComponent<HealthComponent>()->getHp();
    auto timer = owner->getComponent<TimerComponent>()->timer - owner->getComponent<TimerComponent>()->actualTime;
    
    if (health <= 0 ) {
        setScreen(screen["Death"]);
    }
    else if (timer <= 0) {
        setScreen(screen["Win"]);    
    }
    else if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Pause"))) {
        setScreen(screen["Paused"]);
    }
}

