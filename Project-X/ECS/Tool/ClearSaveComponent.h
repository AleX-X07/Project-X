#pragma once
#include "../Component.h"

class ClearSaveComponent : public Component{
public:
    ClearSaveComponent(Object* _owner);
    virtual ~ClearSaveComponent() override = default;
    
    virtual void update(float deltaTime) override;
};
