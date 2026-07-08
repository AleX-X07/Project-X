#include "../Object.h"
#include "SFML/Audio.hpp"
#include "../Bullet/BulletSource.h"

class GameEngine;

class AiFireShot final : public BulletSource
{
public:
    
    float spread;
    float fireRate;
    float speed;
    float randomAngle;

    int BulletQuantity;
    
    float actualTime;
    
    sf::SoundBuffer buffer;
    sf::Sound* sound;
    
    Object& target;
    
public:
    AiFireShot(Object* _owner, Object& _target, int _damage, float _speed, float _spread, float _firerate, int quantity);
    ~AiFireShot() override;
    
    void CreateBullet(Object* _owner, float _angle, float _lifetime);
    
    void update(float dt) override;
    void render() override;
};