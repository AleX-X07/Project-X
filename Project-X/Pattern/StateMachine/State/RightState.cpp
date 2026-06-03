#include "RightState.h"

#include "IdleRightState.h"

RightState::RightState(Object* _owner, std::unordered_map<std::string,nlohmann::basic_json<>>* _mapAnimation) : State(_owner, _mapAnimation) {
    createAnimation("Right");
}

void RightState::update(float deltaTime) {
    State::update(deltaTime);
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Left"))) {
        next = new LeftState(owner,mapAnimation);
        return;
    }
    else if (!sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Right"))) {
        next = new IdleRightState(owner,mapAnimation);
        return;
    }
}


