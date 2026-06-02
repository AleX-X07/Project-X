#pragma once
#include "../../WeaponMain.h"

#include "../../../Box/HitBox.h"
#include "../../../Graphics/RenderComponent.h"
#include "../../../Bullet/BulletSystemComponent.h"
#include "../../../Bullet/BulletManager.h"

class GameEngine;

class LaserGun : public WeaponMain
{
public:
    
public:
    LaserGun(Object* _owner);
    ~LaserGun() override = default;
    
    Object* CreateBullet(float angle) override;
};