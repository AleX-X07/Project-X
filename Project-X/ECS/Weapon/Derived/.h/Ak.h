#pragma once
#include "../../WeaponMain.h"

#include "../../../Box/HitBox.h"
#include "../../../Graphics/RenderComponent.h"
#include "../../../Bullet/BulletSystemComponent.h"
#include "../../../Bullet/BulletManager.h"

class GameEngine;

class Ak : public WeaponMain
{
public:
    
public:
    Ak(Object* _owner);
    ~Ak() override = default;
    
    Object* CreateBullet(float angle) override;
};