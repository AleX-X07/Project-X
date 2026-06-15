#pragma once

#include "../Component.h"

class Quit final : public Component{
public:
    Quit(Object* _owner);
    virtual ~Quit() override= default;
    
    virtual void update(float deltaTime) override;
};
