#pragma once
#include "../State.h"
#include "IdleLeftState.h"
#include "LeftState.h"

class RightState : public State {
public:
    RightState(Object* owner, const char* pathTexture);
    virtual ~RightState() override = default;
    
    virtual void update(float deltaTime) override;
};
