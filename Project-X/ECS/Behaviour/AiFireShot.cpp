#include "AiFireShot.h"
#include "../ChemicalSystem/Giver/ElementGiver.h"
#include "../../Main/GameEngine.h"

AiFireShot::AiFireShot(Object* _owner, Object& _target, int _damage, float _speed, float _spread, float _firerate, int quantity)
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
}

void AiFireShot::update(float dt)
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

void AiFireShot::CreateBullet(Object* _owner, float _angle, float _lifetime)
{
    for (int u = 0; u < BulletQuantity; u++)
    {
        Object* ball = new Object(owner->getPosition(), {25,25});
    
        ball->team = owner->team;
        
        randomAngle = _angle + (rand() / (float)RAND_MAX) * (2 * spread) - spread;
    
        ball->addComponent(new BulletSystemComponent(ball, speed, randomAngle, _lifetime));
        ball->addComponent(new RenderFile(ball, "Assets/Debug/DebugBulletRed.png"));
        ball->addComponent(new HitBox(ball, {25, 25}, true, 10));
        ball->addComponent(new ElementGiver(ball));
        ball->getComponent<ElementGiver>()->addFire(ElementType::Fire, 5, 10, 1);
        
        bullet.push_back(ball);
    }
}

void AiFireShot::render()
{
    for (auto& b : bullet)
    {
        b->render();
    }
}

AiFireShot::~AiFireShot()
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