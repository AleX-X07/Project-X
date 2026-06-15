#include "GrenadeSystemComponent.h"

#include "../../Box/HitBox.h"

GrenadeSystemComponent::GrenadeSystemComponent(Object* _owner, float _speed, float _angle, int _damage, float _ExplosionTimer)
    : Component(_owner)
{
    speed = _speed;
    angle = _angle;
    damage = _damage;
    ExplosionTimer = _ExplosionTimer;
}

void GrenadeSystemComponent::update(float dt)
{
    float rad = angle * 3.1415 / 180;

    ActualPosition.x = owner->getPosition().x;
    ActualPosition.y = owner->getPosition().y;
    
    owner->setPosition({(ActualPosition.x += cos(rad) * speed * dt), (ActualPosition.y += sin(rad) * speed * dt)});
    
    timer += dt;
    timerExp += dt;
    if (timer >= 1.0f / resolution)
    {
        CreateTrailPoint();
        timer = 0;
    }
    
    if ((timerExp >= ExplosionTimer) && !HasExploded) 
    {
        Explode();
        HasExploded = true;
    }
}

void GrenadeSystemComponent::CreateTrailPoint()
{
    Object* point = new Object(ActualPosition, {10, 10});
    
    point->addComponent(new RenderFile(point, "Assets/Debug/DebugPoint.png"));
    Trail.push_back(point);
}

bool GrenadeSystemComponent::isExpired() const
{
    return timerExp >= (ExplosionTimer + 0.5f);
}

void GrenadeSystemComponent::render()
{

}

GrenadeSystemComponent::~GrenadeSystemComponent()
{
    for (auto& point : Trail)
    {
        delete point;
    }
    Trail.clear();
}

void GrenadeSystemComponent::Explode()
{
    auto *explode = owner->getComponent<HitBox>();
    auto *textcomp = owner->getComponent<RenderFile>();
    if (explode != nullptr)
    {
        explode->size = {150, 150};
        explode->pos = {(owner->getPosition().x - 50),(owner->getPosition().y - 50) };
        explode->isactive = true;
    }
    if (textcomp != nullptr)
    {
        owner->setPosition({(owner->getPosition().x - 50),(owner->getPosition().y - 50)});
        owner->setSize({150, 150});
        textcomp->setTexture("Assets/Debug/Collider_DebugTX.png");
    }
}
