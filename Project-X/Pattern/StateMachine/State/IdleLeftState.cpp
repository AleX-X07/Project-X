#include "IdleLeftState.h"

#include <iostream>

#include "LeftState.h"
#include "RightState.h"

IdleLeftState::IdleLeftState(Object* _owner, std::unordered_map<std::string,nlohmann::basic_json<>>* _mapAnimation) : State(_owner, _mapAnimation) {
    createAnimation("IdleLeft");
}

void IdleLeftState::update(float deltaTime) {
    State::update(deltaTime);
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Left"))) {
        next = new LeftState(owner,mapAnimation);
        return;
    }
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Right"))) {
        next = new RightState(owner,mapAnimation);
        return;
    }
}

