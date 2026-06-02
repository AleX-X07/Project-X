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
    if (owner->hasComponent<StateMachineComponent>()) {
        
    }
}

void MovementsComponent::right(float deltaTime)
{
    owner->setPosition({owner->getPosition().x + speed * deltaTime, owner->getPosition().y});
}

void MovementsComponent::up(float deltaTime)
{
    owner->setPosition({owner->getPosition().x, owner->getPosition().y - speed * deltaTime});
}

void MovementsComponent::down(float deltaTime)
{
    owner->setPosition({owner->getPosition().x, owner->getPosition().y + speed * deltaTime});
}