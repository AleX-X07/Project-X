#include "IdleState.h"

#include "LeftState.h"
#include "RightState.h"

IdleState::IdleState(Object* owner, const char* pathTexture) : State(owner, pathTexture) {
    animation = new Animation(pathTexture);
}

void IdleState::update(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Left"))) {
        next = new LeftState(Owner,"Assets/Debug/Trigger_DebugTX.png" );
        return;
    }
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Right"))) {
        next = new RightState(Owner,"Assets/Debug/Collider_DebugTX.png" );
    }
}

