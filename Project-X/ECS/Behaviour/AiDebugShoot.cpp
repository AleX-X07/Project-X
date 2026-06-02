#include "AiDebugShoot.h"
#include "../../Main/GameEngine.h"

AiDebugShoot::AiDebugShoot(Object* _owner, Object& _target, int _damage, float _speed, float _spread, float _firerate)
    : BulletSource(_owner), target(_target)
{
    speed = _speed;
    damage = _damage;
    spread = _spread;
    fireRate = _firerate;
    
    actualTime = 0;
    
    buffer.loadFromFile("Assets/Sound/Shoot.wav");
    sound =  new sf::Sound(buffer);
}

void AiDebugShoot::update(float dt)
{
    actualTime += dt;
    
    if (actualTime >= 1.0f / fireRate)
    {
        float angle = std::atan2(
            target.getPosition().y - owner->getPosition().y,
            target.getPosition().x - owner->getPosition().x
        ) * 180.0f / 3.14159f;
        
        sound->play();
        CreateBullet(owner, angle, 5);
        actualTime = 0;
    }
    
    for (auto& b : bullet)
    {
        b->update(dt);
    }
    
    bullet.erase(
    std::remove_if(bullet.begin(), bullet.end(), [](Object* b)
    {
        auto* mov = b->getComponent<BulletSystemComponent>();
        if (mov && mov->isExpired())
        {
            delete b;
            return true;
        }
        return false;
    }),
    bullet.end()
    );
}

void AiDebugShoot::CreateBullet(Object* _owner, float _angle, float _lifetime)
{
    Object* ball = new Object(owner->getPosition(), {25,25});
    
    randomAngle = _angle + (rand() / (float)RAND_MAX) * (2 * spread) - spread;
    
    ball->addComponent(new BulletSystemComponent(ball, speed, randomAngle, _lifetime, damage));
    ball->addComponent(new RenderComponent(ball, "Assets/Debug/DebugBulletRed.png"));
    ball->addComponent(new HitBox(ball, {25, 25}));
    bullet.push_back(ball);
}

void AiDebugShoot::render()
{
    for (auto& b : bullet)
    {
        b->render();
    }
}

AiDebugShoot::~AiDebugShoot()
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