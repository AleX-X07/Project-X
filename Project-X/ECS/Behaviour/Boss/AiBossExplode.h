#pragma once
#pragma once

#include "../../Object.h"
#include "SFML/Audio.hpp"
#include "../../Bullet/BulletSource.h"

class GameEngine;

class AiBossExplode final : public BulletSource
{
public:
    float speed;
    float randomAngle;

    int BulletQuantity;
    
    sf::SoundBuffer buffer;
    sf::Sound* sound;
public:
    AiBossExplode(Object* _owner, int _damage, float _speed, int quantity);
    ~AiBossExplode() override;
    
    void CreateBullet(Object* _owner, float _lifetime);
    
    void update(float dt) override;
    void render() override;
};