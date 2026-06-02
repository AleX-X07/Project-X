#pragma once
#include "State.h"
#include "../../ECS/Object.h"
#include "../StateMachine/State/IdleLeftState.h"

class StateMachine {
private:
    State * currentState;
    Object* Owner;
    
    std::unordered_map<std::string, std::string>& animation;
    
public:
    StateMachine(Object* owner, std::unordered_map<std::string, std::string>& _animation);
    virtual ~StateMachine();
    
    State* getCurrentState();
    void setCurrentState(State* newState);
    
    void update(float deltaTime);
    void render();
};
