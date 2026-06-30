#include "ExpDisplay.h"
#include "../RenderText.h"
#include "../../Object.h"
#include "../../../Main/GameEngine.h"

ExpDisplay::ExpDisplay(Object* _owner, sf::Vector2f pos, sf::Vector2f size, sf::Color color, std::string file) : Component(_owner), EXP(0) {
    displayEXP = new Object({0,0},{0,0});
}

ExpDisplay::ExpDisplay(Object* _owner, sf::Vector2f pos, int size, sf::Color color, std::string font) : Component(_owner), EXP(0) {
    displayEXP = new Object({0,30},{200,25});
    EmptyBar = new Object({0, 30}, {200, 25});
    
    displayEXP->addComponent(new RenderFile(displayEXP, "Assets/HUD/XPBar.png"));
    barsize = displayEXP->getSize().x;
    
    displayEXP->addComponent(new RenderText(displayEXP, font));
    displayEXP->getComponent<RenderText>()->getText()->setPosition(pos);
    displayEXP->getComponent<RenderText>()->getText()->setCharacterSize(size);
    displayEXP->getComponent<RenderText>()->getText()->setFillColor(color);
    
    EmptyBar->addComponent(new RenderFile(EmptyBar, "Assets/HUD/EmptyBar.png"));
    
    if (owner->hasComponent<ExpManager>()) {
        EXP = owner->getComponent<ExpManager>()->getExp();
    }
}

ExpDisplay::~ExpDisplay() {
    delete displayEXP;
    delete EmptyBar;
    
    displayEXP = nullptr;
    EmptyBar = nullptr;
}

void ExpDisplay::update(float dt) {
    if (owner->hasComponent<ExpManager>()) {
        EXP = owner->getComponent<ExpManager>()->getExp();
    }
    if (displayEXP->hasComponent<RenderText>()) {
        displayEXP->getComponent<RenderText>()->getText()->setString( " Level : " + std::to_string(owner->getComponent<ExpManager>()->level));
    }
    
    auto comp = owner->getComponent<CapacityManager>();
    
    barsize = ((EXP / comp->ExpNeed) * 100) * 2;
    displayEXP->getComponent<RenderFile>()->getRect()->setSize({barsize, 25});
}

void ExpDisplay::render() {
    EmptyBar->render();
    displayEXP->render();
}