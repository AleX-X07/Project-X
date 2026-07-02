#include "ButtonComponent.h"
#include "../../Main/GameEngine.h"

ButtonComponent::ButtonComponent(Object* _owner, sf::Vector2f _pos, sf::Vector2f _size) : Component(_owner) {
    pos = _pos;
    size = _size;
}

void ButtonComponent::update(float deltaTime) {
    if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        click = false;
    }
}

bool ButtonComponent::clicked() {
    if (!click) {
        sf::Vector2i mousePixels = sf::Mouse::getPosition(*GameEngine::getWindow());
        sf::Vector2f mousepos = GameEngine::getWindow()->mapPixelToCoords(mousePixels, GameEngine::getWindow()->getDefaultView());
    
        if (mousepos.x >= pos.x && mousepos.x <= pos.x + size.x
            && mousepos.y >= pos.y && mousepos.y <= pos.y + size.y) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                click = true;
                return true;
            }
        }
    }
    return false;
}
