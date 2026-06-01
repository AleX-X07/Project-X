#include "InputComponent.h"
#include "../Movement/MovementComponent.h"

InputComponent::InputComponent(Object* _owner)
    : Component(_owner)
{
}

void InputComponent::update(float deltaTime)
{
    auto movementsComp = owner->getComponent<movementsComponent>();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) < -deadzone))
    {
        if (movementsComp != nullptr)
        {
            movementsComp->left(deltaTime);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X) > deadzone))
    {
        if (movementsComp != nullptr)
        {
            movementsComp->right(deltaTime);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y) < -deadzone))
    {
        if (movementsComp != nullptr)
        {
            movementsComp->up(deltaTime);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y) > deadzone))
    {
        if (movementsComp != nullptr)
        {
            movementsComp->down(deltaTime);
        }
    }
}