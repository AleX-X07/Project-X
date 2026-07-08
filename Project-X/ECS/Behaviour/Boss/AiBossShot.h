#pragma once

#include "../../Object.h"
#include "SFML/Audio.hpp"
#include "../../Bullet/BulletSource.h"

class GameEngine;

class AiBossShot final : public BulletSource
{
public:

    float spread;
    float fireRate;
    float speed;
    
    float size;

    int BulletQuantity;

    float actualTime;

    sf::SoundBuffer buffer;
    sf::Sound* sound;

    Object& target;
    
    bool fire;

public:
    AiBossShot(Object* _owner, Object& _target, int _damage, float _speed, float _spread, float _firerate, int quantity, bool _fire);
    ~AiBossShot() override;

    void CreateBullet(Object* _owner, float _lifetime);

    void update(float dt) override;
    void render() override;
};
