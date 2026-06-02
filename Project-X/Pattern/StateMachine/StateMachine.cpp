#include "StateMachine.h"

#include "State/IdleRightState.h"


StateMachine::StateMachine(Object* owner, std::unordered_map<std::string, std::string>& _animation) : animation(_animation) {
    Owner = owner;
    currentState = nullptr;
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

