#pragma once
#include "../ScreenManager.h"

class ScreenKey : public ScreenManager {
private:
    std::string name;
    std::string key;
    
public:
    ScreenKey(Object* _owner, Scene* scene, std::string _name, std::string _key);
    virtual ~ScreenKey() override = default;
    
    virtual void update(float deltaTime) override;
};