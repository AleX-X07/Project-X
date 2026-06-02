#include "IdleRightState.h"


IdleRightState::IdleRightState(Object* _owner, const char* pathTexture) : State(_owner, pathTexture) {
    animation = new Animation(_owner, pathTexture);
}

void IdleRightState::update(float deltaTime) {
    State::update(deltaTime);
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Right"))) {
        next = new RightState(owner,"Assets/Debug/Collider_DebugTX.png" );
        return;
    }
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Left"))) {
        next = new LeftState(owner,"Assets/Debug/Trigger_DebugTX.png" );
        return;
    }
}
