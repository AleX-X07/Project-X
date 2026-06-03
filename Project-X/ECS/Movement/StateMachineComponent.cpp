#include "StateMachineComponent.h"
#include "../../Pattern/StateMachine/StateMachine.h"
#include "../../Pattern/StateMachine/State.h"


StateMachineComponent::StateMachineComponent(Object* _owner) : Component(_owner){
    SM = nullptr;
}

StateMachineComponent::~StateMachineComponent() {
    delete SM;
    SM = nullptr;
}

void StateMachineComponent::setSM(std::unordered_map<std::string, nlohmann::basic_json<>>* _animation, 
    std::unordered_map<std::string, State*>* _mapState,
    std::string startState) {
    SM = new StateMachine(owner, *_animation, *_mapState, startState);
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
