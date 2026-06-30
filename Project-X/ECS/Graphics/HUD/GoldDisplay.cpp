#include "GoldDisplay.h"
#include "../RenderText.h"
#include "../../Object.h"
#include "../../../Main/GameEngine.h"

GoldDisplay::GoldDisplay(Object* _owner, sf::Vector2f pos, sf::Vector2f size, sf::Color color, std::string file) : Component(_owner), Gold(0) {
    displayGold = new Object({0,0},{0,0});
}

GoldDisplay::GoldDisplay(Object* _owner, sf::Vector2f pos, int size, sf::Color color, std::string font) : Component(_owner), Gold(0) {
    displayGold = new Object({30,60},{200,25});
    displayGold->addComponent(new RenderText(displayGold, font));
    displayGold->getComponent<RenderText>()->getText()->setPosition(pos);
    displayGold->getComponent<RenderText>()->getText()->setCharacterSize(size);
    displayGold->getComponent<RenderText>()->getText()->setFillColor(color);
    
    displayGold->addComponent(new RenderFile(displayGold, "Assets/HUD/Sac.png"));
    displayGold->getComponent<RenderFile>()->getRect()->setPosition({0, 60});
    displayGold->getComponent<RenderFile>()->getRect()->setSize({25, 25});
}

GoldDisplay::~GoldDisplay() {
    delete displayGold;
    displayGold = nullptr;
}

void GoldDisplay::update(float dt) {
    if (owner->hasComponent<ExpManager>()) {
        Gold = owner->getComponent<GoldManager>()->getGold();
    }
    if (displayGold->hasComponent<RenderText>()) {
        displayGold->getComponent<RenderText>()->getText()->setString(std::to_string(Gold));
    }
}

void GoldDisplay::render() {
    displayGold->render();
}