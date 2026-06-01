#pragma once
#include "../../ECS/Object.h"

class State {
private:
    Object* Owner;
    const char* Path;
public:
    State* next;
public:
    State(Object* owner, const char* pathTexture);
    virtual ~State() = default;
    
    virtual void nextState() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;
};
