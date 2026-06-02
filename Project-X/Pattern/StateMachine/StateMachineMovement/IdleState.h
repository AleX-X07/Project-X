#pragma once
#include "../State.h"

class IdleState : public State {
public:
    IdleState(Object* owner, const char* pathTexture);
    virtual ~IdleState() override = default;
    
    virtual void update(float deltaTime) override;
};
