#pragma once
#include "../Object.h"
#include "cmath"

#include "BulletSystemComponent.h"
#include "../Graphics/RenderComponent.h"
#include "../Input/MouseComponent.h"
#include "../Box/Hitbox.h"

class BulletManager : public Component
{
public:
    std::vector<Object*> bullet;
    
    float spread;
    float fireRate;
    int damage;
    float speed;
    float randomAngle;

    float actualTime;
    
public:
    BulletManager(Object* _owner);
    ~BulletManager() override = default;
    
    void CreateBullet(Object* _owner, float _angle, float _lifetime);
    
    void update(float dt) override;
    void render() override;
};