#include "IdleLeftState.h"

#include "LeftState.h"
#include "RightState.h"

IdleLeftState::IdleLeftState(Object* _owner, const char* pathTexture) : State(_owner, pathTexture) {
    animation = new Animation(_owner, pathTexture);
}

void IdleLeftState::update(float deltaTime) {
    State::update(deltaTime);
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Left"))) {
        next = new LeftState(owner,"Assets/Debug/Trigger_DebugTX.png" );
        return;
    }
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Right"))) {
        next = new RightState(owner,"Assets/Debug/Collider_DebugTX.png" );
        return;
    }
}

