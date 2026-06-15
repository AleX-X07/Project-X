#include "State.h"

State::State(Object* _owner, std::unordered_map<std::string,nlohmann::basic_json<>>* _mapAnimation) : mapAnimation(_mapAnimation) {
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
        if (owner->hasComponent<RenderFile>()) {
            owner->getComponent<RenderFile>()->setAnimation(animation);
        }
    }
}


void State::createAnimation(std::string state) {
    std::string anim = (*mapAnimation)[state][0]["Type"];
    nlohmann::basic_json<> data = (*mapAnimation)[state][0];
    std::string texturePath = (*mapAnimation)[state][1];
    if (anim == "Animated") {
        animation = new Animation(owner, texturePath, data["args"]);
        if (owner->hasComponent<RenderFile>()) {
            owner->getComponent<RenderFile>()->setAnimation(animation);
        }
    }
    else if (anim == "No-Animated") {
        if (owner->hasComponent<RenderFile>()) {
            owner->getComponent<RenderFile>()->setTexture((*mapAnimation)[state].back());
        }
    }
    else {
        std::cerr << "Error loading animation type" << "\n";
    }
}