#include "StateMachine.h"

StateMachine::StateMachine(Object* _owner) {
    Owner = _owner;
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
    currentState->update(deltaTime);
    State* nextState = currentState->next;
    if (nextState != nullptr && nextState != currentState) {
        delete currentState;
        currentState = nextState;
        currentState->next() = nullptr;
    }
}

void StateMachine::render() {
    currentState->render();
}

