#pragma once
#include "../Component.h"
#include "../../Pattern/StateMachine/StateMachine.h"

class StateMachineComponent : public Component {
private:
    StateMachine* SM;
    
public:
    StateMachineComponent(Object* _owner);
    ~StateMachineComponent() override;
    
    virtual void update(float deltaTime) override;
    virtual void render() override;
};
