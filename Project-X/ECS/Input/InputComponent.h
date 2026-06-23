#pragma once

#include "../Object.h"
#include "../../Tool/Input.h"
#include "../../Pattern/GamepadType.h"

class InputComponent : public Component
{
public:
    float deadzone = 20;
    AxisMapping mapping;
    
public:
    InputComponent(Object* owner);
    ~InputComponent() override = default;
    
    void update(float dt) override;
};