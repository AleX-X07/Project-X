#include "MouseComponent.h"
#include "../../Main/GameEngine.h"


MouseComponent::MouseComponent(Object* _owner) : Component(_owner) {
    mapping = GamepadUtils::getMapping(0);
    selected = false;
}

void MouseComponent::update(float deltaTime) {

}

sf::Vector2i MouseComponent::getMousePosition() {
    return sf::Mouse::getPosition(*GameEngine::getWindow());
}

bool MouseComponent::keepClick() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        return true;
    }
    if (GamepadUtils::getTriggerValue(0, mapping, false) > 15) {
        return true;
    }
    return false;
}

bool MouseComponent::clicked() {
    if (Input::getInput()->isMousePressed(sf::Mouse::Button::Left)) {
        return true;
    }
    
    if (GamepadUtils::getTriggerValue(0, mapping, false) > 15) {
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
        if (selected) {
            selected = false;
        }
        else {
            selected = true;
        }
        return true;
    }
    else {
        return false;
    }
}

bool MouseComponent::isSelected() {
    return selected;
}
