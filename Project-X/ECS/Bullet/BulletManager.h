#pragma once

#include "SFML/Audio.hpp"

#include "../Object.h"
#include "cmath"

#include "BulletSystemComponent.h"
#include "../Graphics/RenderComponent.h"
#include "../Input/MouseComponent.h"
#include "../Box/Hitbox.h"

class GameEngine;

class BulletManager : public Component
{
public:
    std::vector<Object*> bullet;
    
    float spread;
    float fireRate;
    int damage;
    float speed;
    float randomAngle;

    float actualTime;
    
    sf::Vector2i mouseScreenPos;
    sf::Vector2f mouseWorldPos;
    
    sf::SoundBuffer buffer;
    sf::Sound* sound;
    
public:
    BulletManager(Object* _owner);
    ~BulletManager() override;
    
    void CreateBullet(Object* _owner, float _angle, float _lifetime);
    
    void update(float dt) override;
    void render() override;
};