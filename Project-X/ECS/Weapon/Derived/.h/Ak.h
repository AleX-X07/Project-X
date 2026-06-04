#pragma once
#include "../../WeaponMain.h"

#include "../../../Box/HitBox.h"
#include "../../../Graphics/RenderComponent.h"
#include "../../../Bullet/BulletLogic/BulletSystemComponent.h"
#include "../../../Bullet/BulletManager.h"
#include "../../../Tool/CameraComponent.h"

class GameEngine;

class Ak : public WeaponMain
{
public:
    
public:
    Ak(Object* _owner);
    ~Ak() override = default;
    
    Object* CreateBullet(float angle) override;
};