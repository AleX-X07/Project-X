#pragma once
#include "../State.h"

class RightState : public State {
public:
    RightState(Object* owner, const char* pathTexture);
    virtual ~RightState() override = default;
    
    virtual void update(float deltaTime) override;
    virtual void render() override;
};
