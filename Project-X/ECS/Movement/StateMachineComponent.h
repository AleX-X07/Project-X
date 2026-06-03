#pragma once
#include <unordered_map>
#include <nlohmann/json.hpp>
#include "../Component.h"

class StateMachine;
class State;

class StateMachineComponent : public Component {
private:
    StateMachine* SM;
    
public:
    StateMachineComponent(Object* _owner);
    ~StateMachineComponent() override;
    
    void setSM(std::unordered_map<std::string, nlohmann::basic_json<>>* _animation,
        std::unordered_map<std::string, State*>* _mapState,
        std::string startState);
    
    virtual void update(float deltaTime) override;
    virtual void render() override;
};
