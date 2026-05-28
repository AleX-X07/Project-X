#include "MouseComponent.h"
#include "../Main/GameEngine.h"


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
    return sf::Mouse::isButtonPressed(sf::Mouse::Button::Left);
}