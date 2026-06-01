#pragma once

// Ne sert que pour debug / Devrat etre refait pour etre mis dans un behavior tree

#include "../Object.h"
#include "SFML/Audio.hpp"
#include "../Bullet/BulletSource.h"

class GameEngine;

class AiDebugShoot final : public BulletSource
{
public:
    
    float spread;
    float fireRate;
    float speed;
    float randomAngle;

    float actualTime;
    
    sf::Vector2i mouseScreenPos;
    sf::Vector2f mouseWorldPos;
    
    sf::SoundBuffer buffer;
    sf::Sound* sound;
    
    Object& target;
    
public:
    AiDebugShoot(Object* _owner, Object& _target, int _damage, float _speed, float _spread, float _firerate);
    ~AiDebugShoot() override;
    
    void CreateBullet(Object* _owner, float _angle, float _lifetime);
    
    void update(float dt) override;
    void render() override;
};