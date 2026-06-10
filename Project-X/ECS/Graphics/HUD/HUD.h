#pragma once
#include "../../Object.h"
#include "../../Tool/CameraComponent.h"

class HUD : public Component {
private:
    std::vector<Component*> myHUD;
    
public:
    HUD(Object* _owner);
    virtual ~HUD() override = default;
    
    virtual void update(float dt) override;
    virtual void render() override;
    
    void addHUD(Component* hud);
};
