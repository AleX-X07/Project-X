#pragma once
#include "../ScreenManager.h"
#include "../../Tool/HealthComponent.h"

class ScreenDeath : public ScreenManager {
private:
    std::string file;
public:
    ScreenDeath(Object* _owner, Scene* scene, std::string _file);
    virtual ~ScreenDeath() override = default;
    
    virtual void update(float deltaTime) override;
};
