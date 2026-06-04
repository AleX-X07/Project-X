#pragma once
#include "../../WeaponMain.h"

#include "../../../Box/HitBox.h"
#include "../../../Graphics/RenderComponent.h"
#include "../../../Bullet/BulletLogic/BulletSystemComponent.h"
#include "../../../Bullet/BulletManager.h"
#include "../../../Tool/CameraComponent.h"

class GameEngine;

class PistolDebug : public WeaponMain
{
public:
    
public:
    PistolDebug(Object* _owner);
    ~PistolDebug() override = default;
    
    Object* CreateBullet(float angle) override;
};