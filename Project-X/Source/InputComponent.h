#pragma once

#include "Object.h"


class InputComponent : public Component
{
public:
    InputComponent(Object* owner);
    ~InputComponent() override = default;
    
    void update(float dt) override;
};
