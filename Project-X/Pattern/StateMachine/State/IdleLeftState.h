#pragma once
#include "../State.h"

class IdleLeftState : public State {
public:
    IdleLeftState(Object* owner, const char* pathTexture);
    virtual ~IdleLeftState() override = default;
    
    virtual void update(float deltaTime) override;
};
