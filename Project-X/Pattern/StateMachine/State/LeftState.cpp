#include "LeftState.h"

#include "IdleLeftState.h"
#include "RightState.h"

LeftState::LeftState(Object* _owner, const char* pathTexture) : State(_owner, pathTexture){
    animation = new Animation(_owner, pathTexture);
}

void LeftState::update(float deltaTime) {
    State::update(deltaTime);
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Right"))) {
        next = new RightState(owner, "Assets/Debug/Collider_DebugTX.png");
        return;
    }
    else if (!sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Left"))) {
        next = new IdleLeftState(owner, "Assets/Debug/DebugR.png");
        return;
    }
}

