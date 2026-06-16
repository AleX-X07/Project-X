#pragma once
#include "../ScreenManager.h"
#include "../../Input/MouseComponent.h"

class ScreenSettings : public ScreenManager{
private:
    std::string file;
    
public:
    ScreenSettings(Object* _owner, Scene* currentScene, std::string _file);
    virtual ~ScreenSettings() override = default;
    
    virtual void update(float deltaTime) override;
};
