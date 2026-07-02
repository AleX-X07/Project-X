#include "HealthDisplay.h"
#include "../RenderText.h"
#include "../../Object.h"
#include "../../../Main/GameEngine.h"
#include "../../Tool/HealthComponent.h"

HealthDisplay::HealthDisplay(Object* _owner, sf::Vector2f pos, sf::Vector2f size, sf::Color color, std::string file) : Component(_owner), HP(0) {
    displayHP = new Object({0,0},{0,0});
}

HealthDisplay::HealthDisplay(Object* _owner, sf::Vector2f pos, int size, sf::Color color, std::string font) : Component(_owner), HP(0) {
    displayHP = new Object({0,0},{100,25});
    EmptyBar = new Object({0, 0}, {100, 25});
    
    displayHP->addComponent(new RenderFile(displayHP, "Assets/HUD/HealtBar.png"));
    barsize = displayHP->getSize().x;
    
    displayHP->addComponent(new RenderText(displayHP, font));
    displayHP->getComponent<RenderText>()->getText()->setPosition(pos);
    displayHP->getComponent<RenderText>()->getText()->setCharacterSize(size);
    displayHP->getComponent<RenderText>()->getText()->setFillColor(color);
    
    
    
    EmptyBar->addComponent(new RenderFile(EmptyBar, "Assets/HUD/EmptyBar.png"));
    
    if (owner->hasComponent<HealthComponent>()) {
        HP = owner->getComponent<HealthComponent>()->getHp();
    }
    
    auto comp = EmptyBar->getComponent<RenderFile>();
    HP *= 2;
    comp->getRect()->setSize({static_cast<float>(HP), 25});
}

HealthDisplay::~HealthDisplay() {
    delete displayHP;
    delete EmptyBar;
    
    displayHP = nullptr;
    EmptyBar = nullptr;
}

void HealthDisplay::update(float dt) {
    if (owner->hasComponent<HealthComponent>()) {
        HP = owner->getComponent<HealthComponent>()->getHp();
        
        EmptyBar->getComponent<RenderFile>()->getRect()->setSize({static_cast<float>(owner->getComponent<HealthComponent>()->MaxHp) * 2, 25});
    }
    if (displayHP->hasComponent<RenderText>()) {
        displayHP->getComponent<RenderText>()->getText()->setString(std::to_string(HP));
    }
    barsize = HP * 2;
    
    displayHP->getComponent<RenderFile>()->getRect()->setSize({barsize, 25});
}

void HealthDisplay::render() {
    EmptyBar->render();
    displayHP->render();
}