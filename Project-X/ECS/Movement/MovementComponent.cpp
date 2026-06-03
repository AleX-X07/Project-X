#include "MovementComponent.h"
#include "../Graphics/RenderComponent.h"

movementsComponent::movementsComponent(Object* _owner, float _speed, sf::Vector2f _LevelSize)
    : Component(_owner)
    , speed(_speed)
{
    LevelSize = _LevelSize;
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
    
    if (owner->getPosition().x < 0)
    {
        owner->setPosition({0, owner->getPosition().y});
    }
}

void movementsComponent::right(float deltaTime)
{
    owner->setPosition({owner->getPosition().x + speed * deltaTime, owner->getPosition().y});
    
    if ((owner->getPosition().x + owner->getSize().x) > LevelSize.x)
    {
        owner->setPosition({(LevelSize.x - owner->getSize().x), owner->getPosition().y});
    }
}

void movementsComponent::up(float deltaTime)
{
    owner->setPosition({owner->getPosition().x, owner->getPosition().y - speed * deltaTime});
    
    if (owner->getPosition().y < 0)
    {
        owner->setPosition({owner->getPosition().x, 0});
    }
}

void movementsComponent::down(float deltaTime)
{
    owner->setPosition({owner->getPosition().x, owner->getPosition().y + speed * deltaTime});
    
    if ((owner->getPosition().y + owner->getSize().y) > LevelSize.y)
    {
        owner->setPosition({owner->getPosition().x, (LevelSize.y - owner->getSize().y)});
    }
}