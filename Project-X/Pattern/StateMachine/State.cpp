#include "State.h"

State::State(Object* owner, const char* pathTexture) {
    Owner = owner;
    next = nullptr;
    animation = nullptr;
}

State::~State() {
    delete animation;
    animation = nullptr;
}

void State::render() {
    if (animation != nullptr) {
        if (Owner->hasComponent<RenderComponent>()) {
            animation->render(*Owner->getComponent<RenderComponent>());
        }
    }
}
