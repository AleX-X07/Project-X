#include "AiBossExplode.h"
#include "../../../Main/GameEngine.h"

AiBossExplode::AiBossExplode(Object* _owner, int _damage, float _speed, int quantity, bool _fire)
    : BulletSource(_owner)
{
    speed = _speed;
    damage = _damage;
    
    BulletQuantity = quantity;
    
    buffer.loadFromFile("Assets/Sound/Shoot.wav");
    sound =  new sf::Sound(buffer);
    
    fire = _fire;
}

void AiBossExplode::CreateBullet(Object* _owner, float _lifetime)
{
    float angle = 0;
    sound->play();
    for (int u = 0; u < BulletQuantity; u++)
    {
        Object* ball = new Object(owner->getPosition(), {25,25});
    
        ball->team = owner->team;
    
        ball->addComponent(new BulletSystemComponent(ball, speed, angle, _lifetime));
        ball->addComponent(new RenderFile(ball, "Assets/Debug/DebugBulletRed.png"));
        ball->addComponent(new HitBox(ball, {25, 25}, true, 10));
        bullet.push_back(ball);
        
        angle += (360 / BulletQuantity);
    }
}

void AiBossExplode::update(float dt) {
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

void AiBossExplode::render()
{
    for (auto& b : bullet)
    {
        b->render();
    }
}

AiBossExplode::~AiBossExplode()
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