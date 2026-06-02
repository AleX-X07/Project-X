#include "StateMachine.h"

#include "StateMachineMovement/IdleState.h"

StateMachine::StateMachine(Object* _owner) {
    Owner = _owner;
    currentState = new IdleState(Owner, "Assets/Debug/Baker.png");
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

void StateMachine::addState(State* newState) {
    states.push_back(newState);
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

