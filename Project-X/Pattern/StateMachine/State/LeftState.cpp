#include "LeftState.h"

#include "IdleLeftState.h"
#include "RightState.h"

LeftState::LeftState(Object* _owner, std::unordered_map<std::string,nlohmann::basic_json<>>* _mapAnimation) : State(_owner, _mapAnimation){
    createAnimation("Left");
}

void LeftState::update(float deltaTime) {
    State::update(deltaTime);
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Right"))) {
        next = new RightState(owner, &mapAnimation);
        return;
    }
    else if (!sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Left"))) {
        next = new IdleLeftState(owner, &mapAnimation);
        return;
    }
}

