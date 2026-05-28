#include "BulletManager.h"

BulletManager::BulletManager(Object* _owner)
    : Component(_owner)
{
    speed = 500;
    damage = 10;
    spread = 5;
    fireRate = 10;
    
    actualTime = 0;
}

void BulletManager::update(float dt)
{
    actualTime += dt;
    
    auto Comp = owner->getComponent<MouseComponent>();
    if (Comp->clicked() && actualTime >= 1.0f / fireRate)
    {
        CreateBullet(owner, (std::atan2(Comp->getMousePosition().y - owner->getPosition().y, Comp->getMousePosition().x - owner->getPosition().x) * 180 / 3.14), 5);
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

void BulletManager::CreateBullet(Object* _owner, float _angle, float _lifetime)
{
    Object* ball = new Object(owner->getPosition(), {25,25});
    
    randomAngle = _angle + (rand() / (float)RAND_MAX) * (2 * spread) - spread;
    
    ball->addComponent(new BulletSystemComponent(ball, speed, randomAngle, _lifetime, damage));
    ball->addComponent(new RenderComponent(ball, "Assets/Debug/Baker.png"));
    ball->addComponent(new HitBox(ball, {25, 25}));
    bullet.push_back(ball);
}

void BulletManager::render()
{
    for (auto& b : bullet)
    {
        b->render();
    }
}
