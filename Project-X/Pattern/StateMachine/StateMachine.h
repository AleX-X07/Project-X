#pragma once
#include <nlohmann/json.hpp>
#include "State.h"
#include "../../ECS/Object.h"
#include "../StateMachine/State/IdleLeftState.h"
#include "../Factories.h"

class StateMachine {
private:
    State * currentState;
    Object* owner;
    
    std::unordered_map<std::string, nlohmann::basic_json<>>& animation;
    std::unordered_map<std::string, State*>& mapState;
    
public:
    StateMachine(Object* owner, 
        std::unordered_map<std::string, nlohmann::basic_json<>>& _animation,
        std::unordered_map<std::string, State*>& mapState,
        std::string startState);
    virtual ~StateMachine();
    
    State* getCurrentState();
    void setCurrentState(State* newState);
    
    void update(float deltaTime);
    void render();
};
