#include "CapaButton.h"
#include "../../Main/GameEngine.h"

CapaButton::CapaButton(Object* _owner, CapacityMain* _capa) : Component(_owner) {
    capa = _capa;
    
    size = { 40 , 40};
    
    rect.setSize(size);
    rect.setPosition({(capa->HUDrect.getPosition().x + 5), (capa->HUDrect.getPosition().y - 45)});
    rect.setFillColor(sf::Color::White);
    
    pos = {(capa->HUDrect.getPosition().x + 5), (capa->HUDrect.getPosition().y - 45)};
}

CapaButton::~CapaButton() {
    
}

void CapaButton::update(float dt) {
    clicked();
}

void CapaButton::render() {
    GameEngine::getWindow()->setView(GameEngine::getWindow()->getDefaultView());
    GameEngine::getWindow()->draw(rect);
    
    auto cam = owner->getComponent<CameraComponent>();
    if (cam != nullptr)
    {
        GameEngine::getWindow()->setView(*cam->view);
    }
}

void CapaButton::clicked() {
    sf::Vector2i mousePixels = sf::Mouse::getPosition(*GameEngine::getWindow());
    sf::Vector2f mousepos = GameEngine::getWindow()->mapPixelToCoords(mousePixels, GameEngine::getWindow()->getDefaultView());
    
    if (mousepos.x >= pos.x && mousepos.x <= pos.x + size.x
        && mousepos.y >= pos.y && mousepos.y <= pos.y + size.y) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
            capa->levelUp();
            auto* comp = owner->getComponent<CapacityManager>();
            if (comp) {
                comp->pending = true;
                comp->offered = false;
            }
        }
    }
}
