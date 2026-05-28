#include "BulletSystemComponent.h"

BulletSystemComponent::BulletSystemComponent(Object* _owner, float _speed, float _angle, float _lifetime, int _damage)
    : Component(_owner)
{
    speed = _speed;
    angle = _angle;
    lifetime = _lifetime;
    damage = _damage;
}

void BulletSystemComponent::update(float dt)
{
    float rad = angle * 3.1415 / 180;

    ActualPosition.x = owner->getPosition().x;
    ActualPosition.y = owner->getPosition().y;
    
    owner->setPosition({(ActualPosition.x += cos(rad) * speed * dt), (ActualPosition.y += sin(rad) * speed * dt)});
    
    lifetime -= dt;
    
    timer += dt;
    if (timer >= 1.0f / resolution)
    {
        CreateTrailPoint();
        timer = 0;
    }
}

void BulletSystemComponent::CreateTrailPoint()
{
    Object* point = new Object(ActualPosition, {10, 10});
    
    point->addComponent(new RenderComponent(point, "Sprite/Debug/DebugPoint.png"));
    Trail.push_back(point);
}

bool BulletSystemComponent::isExpired() const
{
    return lifetime <= 0;
}

void BulletSystemComponent::render()
{
    for (auto& point : Trail)
    {
        point->render();
    }
}

BulletSystemComponent::~BulletSystemComponent()
{
    for (auto& point : Trail)
    {
        delete point;
    }
    Trail.clear();
}