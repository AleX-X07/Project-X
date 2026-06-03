#pragma once
#include <iostream>
#include "../../ECS/Object.h"
#include "../../Tool/Animation.h"
#include "../../Tool/Input.h"
#include "../../ECS/Graphics/RenderComponent.h"

class State {
protected:
    Object* owner;
    Animation* animation;
    std::unordered_map<std::string,nlohmann::basic_json<>>* mapAnimation;
    
public:
    State* next;

public:
    State(Object* owner, std::unordered_map<std::string,nlohmann::basic_json<>>* _mapAnimation);
    virtual ~State();
    
    virtual void update(float deltaTime);
    void render();
    
protected:
    void createAnimation(std::string state);
};
