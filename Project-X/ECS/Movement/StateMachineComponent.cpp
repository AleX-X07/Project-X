#include "StateMachineComponent.h"

StateMachineComponent::StateMachineComponent(Object* _owner) : Component(_owner){
    SM = new StateMachine(_owner);
}

StateMachineComponent::~StateMachineComponent() {
    delete SM;
    SM = nullptr;
}

void StateMachineComponent::update(float deltaTime) {
    SM->update(deltaTime);
}

void StateMachineComponent::render() {
    SM->render();
}
