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
    bool hori = false;
    bool vert = false;
    
    auto movementsComp = owner->getComponent<MovementsComponent>();
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Left")) || (sf::Joystick::getAxisPosition(0, mapping.leftStickX) < -deadzone))
    {
        if (movementsComp != nullptr)
        {
            hori = true;
            movementsComp->left(deltaTime);
        } 
    }
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Right")) || (sf::Joystick::getAxisPosition(0, mapping.leftStickX) > deadzone))
    {
        if (movementsComp != nullptr)
        {
            hori = true;
            movementsComp->right(deltaTime);
        }
    }
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Up")) || (sf::Joystick::getAxisPosition(0, mapping.leftStickY) < -deadzone))
    {
        if (movementsComp != nullptr)
        {
            vert = true;
            movementsComp->up(deltaTime);
        }
    }
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Down")) || (sf::Joystick::getAxisPosition(0, mapping.leftStickY) > deadzone))
    {
        if (movementsComp != nullptr)
        {
            vert = true;
            movementsComp->down(deltaTime);
        }
    }
    
    if (!hori) {
        if (movementsComp) {
            movementsComp->VelocityX = 0;
        }
    }
    if (!vert) {
        if (movementsComp) {
            movementsComp->VelocityY = 0;
        }
    }
}