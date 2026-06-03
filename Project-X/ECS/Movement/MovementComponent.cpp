#include "MovementComponent.h"

#include "StateMachineComponent.h"
#include "../Graphics/RenderComponent.h"

MovementsComponent::MovementsComponent(Object* _owner, float _speed)
    : Component(_owner)
    , speed(_speed)
{
    
}

float MovementsComponent::getSpeed()
{
    return speed;
}

void MovementsComponent::setSpeed(float newSpeed)
{
    speed = newSpeed;
}

void MovementsComponent::left(float deltaTime)
{
    owner->setPosition({owner->getPosition().x - speed * deltaTime, owner->getPosition().y});
    
    if (owner->getPosition().x < 0)
    {
        owner->setPosition({0, owner->getPosition().y});
    }
}

void MovementsComponent::right(float deltaTime)
{
    owner->setPosition({owner->getPosition().x + speed * deltaTime, owner->getPosition().y});
    
    if ((owner->getPosition().x + owner->getSize().x) > levelSize.x)
    {
        owner->setPosition({(levelSize.x - owner->getSize().x), owner->getPosition().y});
    }
}

void MovementsComponent::up(float deltaTime)
{
    owner->setPosition({owner->getPosition().x, owner->getPosition().y - speed * deltaTime});
    
    if (owner->getPosition().y < 0)
    {
        owner->setPosition({owner->getPosition().x, 0});
    }
}

void MovementsComponent::down(float deltaTime)
{
    owner->setPosition({owner->getPosition().x, owner->getPosition().y + speed * deltaTime});
    
    if ((owner->getPosition().y + owner->getSize().y) > LevelSize.y)
    {
        owner->setPosition({owner->getPosition().x, (LevelSize.y - owner->getSize().y)});
    }
}