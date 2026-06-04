#pragma once

#include "../../WeaponMain.h"

#include "../../../Box/HitBox.h"
#include "../../../Graphics/RenderComponent.h"
#include "../../../Bullet/BulletLogic/GrenadeSystemComponent.h"
#include "../../../Bullet/BulletManager.h"
#include "../../../Tool/CameraComponent.h"

class GameEngine;

class GrenadeLauncher : public WeaponMain
{
public:
    
public:
    GrenadeLauncher(Object* _owner);
    ~GrenadeLauncher() override = default;
    
    Object* CreateBullet(float angle) override;
};
