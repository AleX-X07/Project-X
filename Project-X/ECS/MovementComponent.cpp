#include "MovementComponent.h"
#include "RenderComponent.h"

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
    auto comp = owner->getComponent<RenderComponent>();
    if (comp != nullptr)
    {
        comp->setTexture("Assets/Debug/Baker.png");
    }
}

void movementsComponent::right(float deltaTime)
{
    owner->setPosition({owner->getPosition().x + speed * deltaTime, owner->getPosition().y});
    auto comp = owner->getComponent<RenderComponent>();
    if (comp != nullptr)
    {
        comp->setTexture("Assets/Debug/Baker.png");
    }
}

void movementsComponent::up(float deltaTime)
{
    owner->setPosition({owner->getPosition().x, owner->getPosition().y - speed * deltaTime});
    auto comp = owner->getComponent<RenderComponent>();
    if (comp != nullptr)
    {
        comp->setTexture("Assets/Debug/Baker.png");
    }
}

void movementsComponent::down(float deltaTime)
{
    owner->setPosition({owner->getPosition().x, owner->getPosition().y + speed * deltaTime});
    auto comp = owner->getComponent<RenderComponent>();
    if (comp != nullptr)
    {
        comp->setTexture("Assets/Debug/Baker.png");
    }
}