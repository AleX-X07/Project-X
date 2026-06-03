#include "StateMachine.h"

#include "State/IdleRightState.h"


StateMachine::StateMachine(Object* _owner, 
    std::unordered_map<std::string, nlohmann::basic_json<>>& _animation, 
    std::unordered_map<std::string, State*>& _mapState,
    std::string startState) 
: animation(_animation), mapState(_mapState) {
    
    owner = _owner;
    currentState = FactoriesStates::factories[startState](owner,&_animation);
    
}

StateMachine::~StateMachine() {
    delete currentState;
    currentState = nullptr;
}

State* StateMachine::getCurrentState() {
    return currentState;
}

void StateMachine::setCurrentState(State* newState) {
    currentState = newState;
}

void StateMachine::update(float deltaTime) {
    getCurrentState()->update(deltaTime);
    State* nextState = currentState->next;
    if (nextState != nullptr && nextState != currentState) {
        delete currentState;
        currentState = nextState;
        currentState->next = nullptr;
    }
}

void StateMachine::render() {
   currentState->render();
}

