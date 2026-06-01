#include "MovementComponent.h"
#include "../Graphics/RenderComponent.h"

movementsComponent::movementsComponent(Object* _owner, float _speed)
    : Component(_owner)
    , speed(_speed)
{
}

float movementsComponent::getSpeed()
{
    return speed;
}

void movementsComponent::setSpeed(float newSpeed)
{
    speed = newSpeed;
}

void movementsComponent::left(float deltaTime)
{
    owner->setPosition({owner->getPosition().x - speed * deltaTime, owner->getPosition().y});
}

void movementsComponent::right(float deltaTime)
{
    owner->setPosition({owner->getPosition().x + speed * deltaTime, owner->getPosition().y});
}

void movementsComponent::up(float deltaTime)
{
    owner->setPosition({owner->getPosition().x, owner->getPosition().y - speed * deltaTime});
}

void movementsComponent::down(float deltaTime)
{
    owner->setPosition({owner->getPosition().x, owner->getPosition().y + speed * deltaTime});
}