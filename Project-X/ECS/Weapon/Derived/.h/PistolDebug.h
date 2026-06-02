#pragma once
#include "../../WeaponMain.h"

#include "../../../Box/HitBox.h"
#include "../../../Graphics/RenderComponent.h"
#include "../../../Bullet/BulletSystemComponent.h"
#include "../../../Bullet/BulletManager.h"

class GameEngine;

class PistolDebug : public WeaponMain
{
public:
    
public:
    PistolDebug(Object* _owner);
    ~PistolDebug() override = default;
    
    Object* CreateBullet(float angle) override;
};