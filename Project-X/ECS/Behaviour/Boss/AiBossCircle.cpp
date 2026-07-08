#include "AiBossCircle.h"

#include "AiBossExplode.h"
#include "../../../Main/GameEngine.h"

AiBossCircle::AiBossCircle(Object* _owner, int _damage, float _speed, float _spread, float _firerate, bool _fire)
    : BulletSource(_owner)
{
    speed = _speed;
    damage = _damage;
    spread = _spread;
    fireRate = _firerate;
    
    actualAngle = 0;
    
    actualTime = 0;
    
    buffer.loadFromFile("Assets/Sound/Shoot.wav");
    sound =  new sf::Sound(buffer);
    
    fire = _fire;
}

void AiBossCircle::update(float dt)
{
    actualTime += dt;
    
    if ((actualTime >= 1.0f / fireRate) && active)
    {
        sound->play();
        CreateBullet(owner, actualAngle, 5);
        actualTime = 0;
        actualAngle += 15;
    }
    
    if (active) {
        TimerActual += dt;
        if (TimerActual > 10) {
            active = false;
            TimerActual = 0;
        }
    }
}

void AiBossCircle::CreateBullet(Object* _owner, float _angle, float _lifetime)
{
    Object* ball = new Object(owner->getPosition(), {25,25});
    ball->team = owner->team;
    ball->addComponent(new BulletSystemComponent(ball, speed, _angle, _lifetime));
    ball->addComponent(new RenderFile(ball, "Assets/Debug/DebugBulletRed.png"));
    ball->addComponent(new HitBox(ball, {25, 25}, true, 10));
    
    auto* main = owner->getComponent<AiBossExplode>();
    if (main) main->bullet.push_back(ball);
    else bullet.push_back(ball);
}

void AiBossCircle::render()
{
    for (auto& b : bullet)
    {
        b->render();
    }
}

AiBossCircle::~AiBossCircle()
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