#include "StateMachineComponent.h"

StateMachineComponent::StateMachineComponent(Object* _owner) : Component(_owner){
    SM = nullptr;
}

StateMachineComponent::~StateMachineComponent() {
    delete SM;
    SM = nullptr;
}

void StateMachineComponent::setSM(std::unordered_map<std::string, std::string>& _animation) {
    SM = new StateMachine(owner, _animation);
}

void StateMachineComponent::update(float deltaTime) {
    if (SM != nullptr) {
        SM->update(deltaTime);
    }
}

void StateMachineComponent::render() {
    if (SM != nullptr) {
        SM->render();
    }
}
