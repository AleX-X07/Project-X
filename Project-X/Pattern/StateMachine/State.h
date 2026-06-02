#pragma once
#include "../../ECS/Object.h"
#include "../../Tool/Animation.h"
#include "../../Tool/Input.h"

class State {
protected:
    Object* Owner;
    Animation* animation;
    
public:
    State* next;

public:
    State(Object* owner, const char* pathTexture);
    virtual ~State();
    
    virtual void update(float deltaTime) = 0;
    void render();
};
