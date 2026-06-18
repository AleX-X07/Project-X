#include "HealthBar.h"

#include "HealthComponent.h"
#include "../../Main/GameEngine.h"

HealthBar::HealthBar(Object* _owner, sf::Color color) : Component(_owner) {
    fill.setFillColor(color);
    bar.setFillColor(sf::Color::Black);
    
    fill.setSize({owner->getSize().x, 10});
    bar.setSize({owner->getSize().x, 10});
}

HealthBar::~HealthBar() {
}

void HealthBar::update(float deltaTime) {
    bar.setPosition({owner->getPosition().x, owner->getPosition().y - 20});
    fill.setPosition({owner->getPosition().x, owner->getPosition().y - 20});
    
    auto comp = owner->getComponent<HealthComponent>();
    if (comp) {
        float filling = (static_cast<float>(comp->hp) / static_cast<float>(comp->MaxHp)) * bar.getSize().x;
        fill.setSize({filling, 10});
    }
}

void HealthBar::render() {
    GameEngine::getWindow()->draw(bar);
    GameEngine::getWindow()->draw(fill);
}
