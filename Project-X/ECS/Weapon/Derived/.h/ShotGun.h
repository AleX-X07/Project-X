#pragma once
#include "../../WeaponMain.h"

#include "../../../Box/HitBox.h"
#include "../../../Graphics/RenderComponent.h"
#include "../../../Bullet/BulletLogic/BulletSystemComponent.h"
#include "../../../Bullet/BulletManager.h"
#include "../../../Tool/CameraComponent.h"

class GameEngine;

class shotgun : public WeaponMain
{
public:
    
public:
    shotgun(Object* _owner);
    ~shotgun() override = default;
    
    void update(float deltaTime) override;
    
    Object* CreateBullet(float angle) override;
};