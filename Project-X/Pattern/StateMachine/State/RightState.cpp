#include "RightState.h"

#include "IdleRightState.h"

RightState::RightState(Object* _owner, const char* pathTexture) : State(_owner, pathTexture) {
    animation = new Animation(_owner, pathTexture);
}

void RightState::update(float deltaTime) {
    State::update(deltaTime);
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Left"))) {
        next = new LeftState(owner, "Assets/Debug/Trigger_DebugTX.png");
        return;
    }
    else if (!sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Right"))) {
        next = new IdleRightState(owner, "Assets/Debug/Baker.png");
        return;
    }
}


