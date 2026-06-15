#include "HealthDisplay.h"
#include "../RenderText.h"
#include "../../Object.h"
#include "../../../Main/GameEngine.h"
#include "../../Tool/HealthComponent.h"

HealthDisplay::HealthDisplay(Object* _owner, sf::Vector2f pos, sf::Vector2f size, sf::Color color, std::string file) : Component(_owner), HP(0) {
    displayHP = new Object({0,0},{0,0});
}

HealthDisplay::HealthDisplay(Object* _owner, sf::Vector2f pos, int size, sf::Color color, std::string font) : Component(_owner), HP(0) {
    displayHP = new Object({0,0},{0,0});
    displayHP->addComponent(new RenderText(displayHP, font));
    displayHP->getComponent<RenderText>()->getText()->setPosition(pos);
    displayHP->getComponent<RenderText>()->getText()->setCharacterSize(size);
    displayHP->getComponent<RenderText>()->getText()->setFillColor(color);
}

HealthDisplay::~HealthDisplay() {
    delete displayHP;
    displayHP = nullptr;
}

void HealthDisplay::update(float dt) {
    if (owner->hasComponent<HealthComponent>()) {
        HP = owner->getComponent<HealthComponent>()->getHp();
    }
    if (displayHP->hasComponent<RenderText>()) {
        displayHP->getComponent<RenderText>()->getText()->setString(std::to_string(HP));
    }
}

void HealthDisplay::render() {
    displayHP->render();
}


