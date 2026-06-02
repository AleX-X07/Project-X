#include "LeftState.h"

LeftState::LeftState(Object* owner, const char* pathTexture) : State(owner, pathTexture){
    animation = new Animation(pathTexture);
}

void LeftState::update(float deltaTime) {
}

