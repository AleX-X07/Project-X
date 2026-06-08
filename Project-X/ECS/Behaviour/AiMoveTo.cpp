#include "AiMoveTo.h"

AiMoveTo::AiMoveTo(Object* _owner, std::vector<Object*>& _objects, float _speed) : Component(_owner), other(_objects)
{
    speed = _speed;
    
    for (auto c : other)
    {
        auto comp = c->getComponent<BulletManager>();
        if (comp != nullptr)
        {
            target = c;
        }
    }
}

AiMoveTo::~AiMoveTo()
{
    delete target;
    target = nullptr;
}

void AiMoveTo::update(float dt)
{
    float rad = std::atan2(target->getPosition().y - owner->getPosition().y, target->getPosition().x - owner->getPosition().x);

    actualPos.x = owner->getPosition().x;
    actualPos.y = owner->getPosition().y;
    
    owner->setPosition({(actualPos.x += cos(rad) * speed * dt), (actualPos.y += sin(rad) * speed * dt)});
}