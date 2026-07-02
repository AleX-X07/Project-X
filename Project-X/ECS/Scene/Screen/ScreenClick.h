#pragma once
#include "../ScreenManager.h"

class ScreenClick : public ScreenManager {
private:
    std::string name;
    
public:
    ScreenClick(Object* _owner, Scene* scene, std::string _name);
    virtual ~ScreenClick() override = default;
    
    virtual void update(float deltaTime) override;
};
