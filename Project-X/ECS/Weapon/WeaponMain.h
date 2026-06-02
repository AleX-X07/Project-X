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
    
public:
    WeaponMain(Object* _owner);
    ~WeaponMain() override = default;

    virtual Object* CreateBullet(float angle);
};