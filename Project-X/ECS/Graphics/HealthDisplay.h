#pragma once
#include "../Component.h"

class Object;
class HealthComponent;
class GameEngine;
class RenderText;

class HealthDisplay : public Component {
private:
    int HP;
public:
    HealthDisplay(Object* owner);
    virtual ~HealthDisplay() override = default;
    
    virtual void update(float dt) override;
    virtual void render() override;
};
