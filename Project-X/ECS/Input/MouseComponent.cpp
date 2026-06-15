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
    if (Input::getInput()->isMousePressed(sf::Mouse::Button::Left)) {
        return true;
    }
    if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z) < -10) {
        return true;
    }
    return false;
}

bool MouseComponent::isClick() {
    sf::Vector2i mousePixel = sf::Mouse::getPosition(*GameEngine::getWindow());
    sf::Vector2f mousePos = GameEngine::getWindow()->mapPixelToCoords(mousePixel, GameEngine::getWindow()->getDefaultView()); 
    
    sf::FloatRect bounds(
        {owner->getPosition().x,
        owner->getPosition().y},
        {owner->getSize().x,
        owner->getSize().y}
    );
    
    if (clicked() && bounds.contains(sf::Vector2f(mousePos))) {
        return true;
    }
    else {
        return false;
    }
}
