#include "State.h"

State::State(Object* _owner, std::unordered_map<std::string,nlohmann::basic_json<>>* _mapAnimation) : mapAnimation(*_mapAnimation) {
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


void State::createAnimation(std::string state) {
    std::string anim = mapAnimation[state][0]["Type"];
    nlohmann::basic_json<> data = mapAnimation[state][0]["Type"];
    if (anim == "Animated") {
        animation = new Animation(owner, data["args"]);
    }
    else if (anim == "No-Animated") {
        if (owner->hasComponent<RenderComponent>()) {
            owner->getComponent<RenderComponent>()->setTexture(mapAnimation[state].back());
        }
    }
    else {
        std::cerr << "Error loading animation type" << "\n";
    }
}