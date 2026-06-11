#include "MouseComponent.h"
#include "../../Main/GameEngine.h"


MouseComponent::MouseComponent(Object* _owner)
    : Component(_owner)
{
}

void MouseComponent::update(float deltaTime)
{

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

bool MouseComponent::isClick() {
    sf::Vector2i mousePos = sf::Mouse::getPosition(*GameEngine::getWindow());
    
    sf::FloatRect bounds(
        {owner->getPosition().x,
        owner->getPosition().y},
        {owner->getSize().x,
        owner->getSize().y}
    );
    
    return bounds.contains(sf::Vector2f(mousePos));
}
