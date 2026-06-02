#pragma once
#include "../State.h"
#include "RightState.h"
#include "LeftState.h"

class IdleRightState : public State {
public:
    IdleRightState(Object* owner, const char* pathTexture);
    virtual ~IdleRightState() override = default;
    
    virtual void update(float deltaTime) override;
};
