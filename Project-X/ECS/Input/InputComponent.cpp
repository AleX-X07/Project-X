#include "InputComponent.h"

#include <iostream>

#include "../Movement/MovementComponent.h"

InputComponent::InputComponent(Object* _owner)
    : Component(_owner)
{
    mapping = GamepadUtils::getMapping(0);
}

void InputComponent::update(float deltaTime)
{
    auto movementsComp = owner->getComponent<MovementsComponent>();
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Left")) || (sf::Joystick::getAxisPosition(0, mapping.leftStickX) < -deadzone))
    {
        if (movementsComp != nullptr)
        {
            movementsComp->left(deltaTime);
        }
    }
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Right")) || (sf::Joystick::getAxisPosition(0, mapping.leftStickX) > deadzone))
    {
        if (movementsComp != nullptr)
        {
            movementsComp->right(deltaTime);
        }
    }
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Up")) || (sf::Joystick::getAxisPosition(0, mapping.leftStickY) < -deadzone))
    {
        if (movementsComp != nullptr)
        {
            movementsComp->up(deltaTime);
        }
    }
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Down")) || (sf::Joystick::getAxisPosition(0, mapping.leftStickY) > deadzone))
    {
        if (movementsComp != nullptr)
        {
            movementsComp->down(deltaTime);
        }
    }
}