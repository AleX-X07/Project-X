#include "State.h"

State::State(Object* _owner, const char* pathTexture) {
    owner = _owner;
    next = nullptr;
    animation = nullptr;
}

State::~State() {
    delete animation;
    animation = nullptr;
}

void State::update(float deltaTime) {
    if (next != nullptr) {
        return;
    }
}

void State::render() {
    if (animation != nullptr) {
        if (owner->hasComponent<RenderComponent>()) {
            animation->render();
        }
    }
}
