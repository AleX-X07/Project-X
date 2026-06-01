#pragma once

#include "../Object.h"
#include "../../Tool/Input.h"

class InputComponent : public Component
{
public:
    float deadzone = 20;
    
public:
    InputComponent(Object* owner);
    ~InputComponent() override = default;
    
    void update(float dt) override;
};