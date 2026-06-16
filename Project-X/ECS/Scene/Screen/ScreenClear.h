#pragma once
#include "../ScreenManager.h"
#include "../../Input/MouseComponent.h"
#include "../../../Scene/Scene.h"

class ScreenClear : public ScreenManager {
public:
    ScreenClear(Object* _owner, Scene* currentScene);
    virtual ~ScreenClear() override = default;
    
    virtual void update(float deltaTime) override;
};
