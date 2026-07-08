#pragma once

#include "../../Object.h"
#include "SFML/Audio.hpp"
#include "../../Bullet/BulletSource.h"

class GameEngine;

class AiBossCircle final : public BulletSource
{
public:

    float spread;
    float fireRate;
    float speed;
    
    float size;
    float actualAngle;

    float actualTime = 0;
    
    float TimerActual = 0;
    float timer = 0;
    
    bool active = false;

    bool fire;
    
    sf::SoundBuffer buffer;
    sf::Sound* sound;

public:
    AiBossCircle(Object* _owner, int _damage, float _speed, float _spread, float _firerate, bool _fire);
    ~AiBossCircle() override;

    void CreateBullet(Object* _owner, float _angle, float _lifetime);

    void update(float dt) override;
    void render() override;
};
