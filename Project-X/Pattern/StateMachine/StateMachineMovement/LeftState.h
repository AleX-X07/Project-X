#pragma once
#include "../State.h"

class LeftState : public State {
public:
    LeftState(Object* owner, const char* pathTexture);
    virtual ~LeftState() override = default;
    
    virtual void update(float deltaTime) override;
    virtual void render() override;
};
