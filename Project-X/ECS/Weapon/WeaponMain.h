#pragma once
#include "../Object.h"
#include <fstream>

#include "../Box/HitBox.h"
#include "../Graphics/RenderComponent.h"
#include "../Bullet/BulletLogic/BulletSystemComponent.h"
#include "../Tool/CameraComponent.h"

class BulletManager;
class GameEngine;

class WeaponMain : public Component
{
public:
    float spread;
    float fireRate;
    float speed;
    int Bulletquantity;
    float damage;
    
    std::string WeaponName;
    std::string WeaponImage;
    
    float shakeIntensity;
    float shakeDuration;
    
    bool hasrecoil;

public:
    Object* WeaponRender;
    
    sf::Vector2f recoilStartPos;
    sf::Vector2f recoilTargetPos;
    float recoilTime = 1.f;
    
    float Xjoystick;
    float Yjoystick;
    
    sf::Vector2f MouseWorldPosition;
    
    float weaponAngle;
    
public:
    WeaponMain(Object* _owner, std::string file);
    ~WeaponMain() override = default;

    void update(float deltaTime) override;
    void render() override;
    
    void recoil(float angle);
    void ChangeWeapon(std::string file);
    
    virtual Object* CreateBullet(float angle);
};