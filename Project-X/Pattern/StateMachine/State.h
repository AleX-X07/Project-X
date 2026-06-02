#pragma once
#include "../../ECS/Object.h"
#include "../../Tool/Animation.h"
#include "../../Tool/Input.h"
#include "../../ECS/Graphics/RenderComponent.h"

class State {
protected:
    Object* owner;
    Animation* animation;
    
public:
    State* next;

public:
    State(Object* owner, const char* pathTexture);
    virtual ~State();
    
    virtual void update(float deltaTime);
    void render();
};
