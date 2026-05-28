#include "InputComponent.h"
#include "MovementComponent.h"

InputComponent::InputComponent(Object* _owner)
    : Component(_owner)
{
}

void InputComponent::update(float deltaTime)
{
    auto movementsComp = owner->getComponent<movementsComponent>();
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Left")))
    {
        if (movementsComp != nullptr)
        {
            movementsComp->left(deltaTime);
        }
    }
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Right")))
    {
        if (movementsComp != nullptr)
        {
            movementsComp->right(deltaTime);
        }
    }
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Up")))
    {
        if (movementsComp != nullptr)
        {
            movementsComp->up(deltaTime);
        }
    }
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Down")))
    {
        if (movementsComp != nullptr)
        {
            movementsComp->down(deltaTime);
        }
    }
}