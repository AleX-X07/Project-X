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
    actualPos = owner->getPosition();
    if (actualPos.x < target->getPosition().x)
        actualPos.x += speed * dt;
    else if (actualPos.x > target->getPosition().x)
        actualPos.x -= speed * dt;

    if (actualPos.y < target->getPosition().y)
        actualPos.y += speed * dt;
    else if (actualPos.y > target->getPosition().y)
        actualPos.y -= speed * dt;
    
    owner->setPosition(actualPos);
}
