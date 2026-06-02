#pragma once
#include <unordered_map>
#include "../Component.h"
#include "../../Pattern/StateMachine/StateMachine.h"

class StateMachineComponent : public Component {
private:
    StateMachine* SM;
    
public:
    StateMachineComponent(Object* _owner);
    ~StateMachineComponent() override;
    
    void setSM(std::unordered_map<std::string, std::string>& _animation);
    
    virtual void update(float deltaTime) override;
    virtual void render() override;
};
