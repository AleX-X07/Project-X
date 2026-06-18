#pragma once
#include "../CapacityMain.h"

class CA_BulletExplode : public CapacityMain {
public:
    float Quantity;
    float speed;
    float damage;
    
    float Angle;
public:
    CA_BulletExplode(Object* _owner, float _Quantity, float _Cooldown);
    ~CA_BulletExplode() override = default;
    
    void update(float dt) override;
    
    void activate() override;
    void Shot();
    
    void levelUp() override;
};