#include "InputComponent.h"

#include <iostream>

#include "../Capacity/CapacityMain.h"
#include "../Movement/MovementComponent.h"

InputComponent::InputComponent(Object* _owner)
    : Component(_owner)
{
}

void InputComponent::update(float deltaTime)
{
    auto movementsComp = owner->getComponent<MovementsComponent>();
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Left")) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) < -deadzone))
    {
        if (movementsComp != nullptr)
        {
            movementsComp->left(deltaTime);
        }
    }
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Right")) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) > deadzone))
    {
        if (movementsComp != nullptr)
        {
            movementsComp->right(deltaTime);
        }
    }
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Up")) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y) < -deadzone))
    {
        if (movementsComp != nullptr)
        {
            movementsComp->up(deltaTime);
        }
    }
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Down")) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y) > deadzone))
    {
        if (movementsComp != nullptr)
        {
            movementsComp->down(deltaTime);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
    {
        auto Comp = owner->getComponent<CapacityMain>();
        if (Comp != nullptr) {
            Comp->Activate();
        }
    }
}