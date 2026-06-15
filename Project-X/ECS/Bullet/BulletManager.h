#pragma once

#include "SFML/Audio.hpp"
#include "BulletSource.h"

#include "../Object.h"
#include "cmath"

#include "BulletLogic/BulletSystemComponent.h"
#include "../Graphics/RenderComponent.h"
#include "../Input/MouseComponent.h"
#include "../Box/Hitbox.h"
#include "../Weapon/WeaponMain.h"

class GameEngine;

class BulletManager : public BulletSource
{
public:
    WeaponMain* weapon;
    
    float Xjoystick;
    float Yjoystick;
    
    float randomAngle;
    float actualTime;
    
    sf::Vector2i mouseScreenPos;
    sf::Vector2f mouseWorldPos;
    
    sf::SoundBuffer buffer;
    sf::Sound* sound;
    
    sf::SoundBuffer bufferBoom;
    sf::Sound* soundBoom;
    
public:
    BulletManager(Object* _owner);
    ~BulletManager() override;
    
    void CreateBullet(Object* _owner, float _angle, float _lifetime);
    
    void update(float dt) override;
    void render() override;
    
    void SetWeapon(WeaponMain* _weapon);
    
    void setspread(float _spread);
    void setfireRate(float _firerate);
    void setspeed(float _speed);
    void setBulletQuantity(int _quantity);
    void setAll(float _spread, float _firerate, float _speed, int _quantity);
};