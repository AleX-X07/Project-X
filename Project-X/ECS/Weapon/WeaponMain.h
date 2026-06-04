#pragma once
#include "../Object.h"

class GameEngine;

class WeaponMain : public Component
{
public:
    float spread;
    float fireRate;
    float speed;
    int Bulletquantity;
    
    std::string WeaponName;
    
    float shakeIntensity;
    float shakeDuration;
    
    sf::Vector2f recoilStartPos;
    sf::Vector2f recoilTargetPos;
    float recoilTime = 1.f;
    
public:
    WeaponMain(Object* _owner);
    ~WeaponMain() override = default;

    void update(float deltaTime) override;
    
    virtual Object* CreateBullet(float angle);
};