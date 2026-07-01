#pragma once
#include "../Object.h"
#include <fstream>

#include "../Box/HitBox.h"
#include "../Graphics/RenderFile.h"
#include "../Bullet/BulletLogic/BulletSystemComponent.h"
#include "../Tool/CameraComponent.h"
#include "../../Tool/Globals.h"
#include "../../Pattern/GamepadType.h"

class BulletManager;
class GameEngine;
class WeaponReader;

struct argsWeapon {
    std::string WeaponName;
    std::string WeaponImage;
    std::string BulletImage;
    
    sf::Vector2f size;
    sf::Vector2f bulletSize;
    sf::Vector2f positionOnPlayer;
    
    float spread;
    float fireRate;
    float speed;
    int Bulletquantity;
    int damage;
    float lifeTime;
    
    float shakeIntensity;
    float shakeDuration;
    
    bool hasrecoil;
    float recoilTime;
    
    int price;
};

class WeaponMain : public Component
{
public:
    AxisMapping mapping;
    
    argsWeapon myArgs;
    
    bool HasFire = false;
    bool HasIce = false;
    bool HasPoison = false;
    bool HasLightning = false;
    
public:
    Object* WeaponRender;
    
    sf::Vector2f recoilStartPos;
    sf::Vector2f recoilTargetPos;
    
    float Xjoystick;
    float Yjoystick;
    
    sf::Vector2f MouseWorldPosition;
    
    float weaponAngle;
    
public:
    WeaponMain(Object* _owner, std::string weapon);
    ~WeaponMain() override = default;

    void update(float deltaTime) override;
    void render() override;
    
    void recoil(float angle);
    void ChangeWeapon(argsWeapon newWeapon);
    void CollisionCeck();
    
    virtual Object* CreateBullet(float angle);
};