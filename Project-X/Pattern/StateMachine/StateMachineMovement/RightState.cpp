#include "RightState.h"

RightState::RightState(Object* owner, const char* pathTexture) : State(owner, pathTexture) {
    animation = new Animation(pathTexture);
}

void RightState::update(float deltaTime) {
}


