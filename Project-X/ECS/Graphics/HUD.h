#pragma once
#include "../Object.h"
#include "../Tool/CameraComponent.h"

class HUD : public Component {
public:
    HUD(Object* _owner);
    virtual ~HUD() override = default;
    
    virtual void update(float dt) override;
    virtual void render() override;
};
