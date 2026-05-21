#pragma once

#include "Object.h"


class InputComponent : public Component
{
public:
    InputComponent(gameObject* owner);
    ~InputComponent() override = default;
    
    void update(float dt) override;
};
