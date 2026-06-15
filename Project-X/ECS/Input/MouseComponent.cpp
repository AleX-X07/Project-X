#include "MouseComponent.h"
#include "../../Main/GameEngine.h"


MouseComponent::MouseComponent(Object* _owner)
    : Component(_owner)
{
}

void MouseComponent::update(float deltaTime)
{
    //std::cout << owner->getPosition().x << " " << owner->getPosition().y << "\n";
}

sf::Vector2i MouseComponent::getMousePosition() {
    return sf::Mouse::getPosition(*GameEngine::getWindow());
}

bool MouseComponent::clicked() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        return true;
    }
    if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z) < -10) {
        return true;
    }
    return false;
}