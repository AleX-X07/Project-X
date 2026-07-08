#include "AiBossShot.h"

#include "AiBossExplode.h"
#include "../../../Main/GameEngine.h"

AiBossShot::AiBossShot(Object* _owner, Object& _target, int _damage, float _speed, float _spread, float _firerate, int quantity, bool _fire)
    : BulletSource(_owner), target(_target)
{
    speed = _speed;
    damage = _damage;
    spread = _spread;
    fireRate = _firerate;
    
    BulletQuantity = quantity;
    
    actualTime = 0;
    
    buffer.loadFromFile("Assets/Sound/Shoot.wav");
    sound =  new sf::Sound(buffer);
    
    fire = _fire;
}

void AiBossShot::update(float dt)
{

}

void AiBossShot::CreateBullet(Object* _owner, float _lifetime)
{
    float angle = std::atan2(
        target.getPosition().y - owner->getPosition().y,
        target.getPosition().x - owner->getPosition().x
    ) * 180.0f / 3.14159f;
    
    BulletQuantity = 3;
    float newangle = angle - ((BulletQuantity - 1) * 20 / 2.0f);
    
    for (int u = 0; u < BulletQuantity; u++)
    {
        Object* ball = new Object(owner->getPosition(), {50,50});
        ball->team = owner->team;
        ball->addComponent(new BulletSystemComponent(ball, speed, newangle, _lifetime));
        ball->addComponent(new RenderFile(ball, "Assets/Debug/DebugBulletRed.png"));
        ball->addComponent(new HitBox(ball, {50, 50}, true, 30));
        
        auto* main = owner->getComponent<AiBossExplode>();
        if (main) main->bullet.push_back(ball);
        else bullet.push_back(ball);
        
        newangle += 20;
    }
}

void AiBossShot::render()
{
    for (auto& b : bullet)
    {
        b->render();
    }
}

AiBossShot::~AiBossShot()
{
    for (auto z : bullet)
    {
        delete z;
        z = nullptr;
    }
    bullet.clear();
    
    delete sound;
    sound = nullptr;
}