#pragma once
#include "State.h"
#include "../../ECS/Object.h"

class StateMachine {
private:
    State * currentState;
    Object* Owner;
    
    std::vector<State*> states;
    
public:
    StateMachine(Object* owner);
    virtual ~StateMachine();
    
    State* getCurrentState();
    void setCurrentState(State* newState);
    
    void addState(State* newState);
    
    void update(float deltaTime);
    void render();
};
