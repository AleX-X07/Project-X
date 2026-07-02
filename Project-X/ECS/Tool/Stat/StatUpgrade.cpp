#include "StatUpgrade.h"

#include "../ButtonComponent.h"
#include "../../Graphics/RenderFile.h"
#include "../../Graphics/RenderText.h"
#include "../../../Writer/SaveWriter.h"

StatUpgrade::StatUpgrade(int _Level, float _MaxLevel, int _id, std::string _name) {
    Level = _Level;
    MaxLevel = _MaxLevel;
    id = _id;
    Name = _name;
    
    ButtonMinus = new Object({100, (100 * static_cast<float>(id))}, {25, 25});
    ButtonMinus->addComponent(new ButtonComponent(ButtonMinus, ButtonMinus->getPosition(), {25, 25}));
    ButtonMinus->addComponent(new RenderFile(ButtonMinus, "Assets/HUD/Minus.png"));
    
    ButtonPlus = new Object({200, (100 * static_cast<float>(id))}, {25, 25});
    ButtonPlus->addComponent(new ButtonComponent(ButtonPlus, ButtonPlus->getPosition(), {25, 25}));
    ButtonPlus->addComponent(new RenderFile(ButtonPlus, "Assets/HUD/Plus.png"));
    
    Bar = new Object({150, 100 * static_cast<float>(id)}, {0, 0});
    Bar->addComponent(new RenderText(Bar, "Assets/Font/Brown Cookies.otf"));
    Bar->getComponent<RenderText>()->getText()->setPosition({150, 100 * static_cast<float>(id)});
    Bar->getComponent<RenderText>()->getText()->setCharacterSize(24);
    Bar->getComponent<RenderText>()->getText()->setFillColor(sf::Color::Black);
    
    Text = new Object({150, 100 * static_cast<float>(id)}, {0, 0});
    Text->addComponent(new RenderText(Bar, "Assets/Font/Brown Cookies.otf"));
    Text->getComponent<RenderText>()->getText()->setPosition({250, 100 * static_cast<float>(id)});
    Text->getComponent<RenderText>()->getText()->setCharacterSize(24);
    Text->getComponent<RenderText>()->getText()->setFillColor(sf::Color::Black);
    
    Gold = new Object({150, 100 * static_cast<float>(id)}, {0, 0});
    Gold->addComponent(new RenderText(Bar, "Assets/Font/Brown Cookies.otf"));
    Gold->getComponent<RenderText>()->getText()->setPosition({500, 0 * static_cast<float>(id)});
    Gold->getComponent<RenderText>()->getText()->setCharacterSize(24);
    Gold->getComponent<RenderText>()->getText()->setFillColor(sf::Color::Black);
}

StatUpgrade::~StatUpgrade() {
    delete ButtonMinus;
    delete ButtonPlus;
    delete Bar;
    
    ButtonMinus = nullptr;
    ButtonPlus = nullptr;
    Bar = nullptr;
}

void StatUpgrade::update(float dt) {
    Bar->getComponent<RenderText>()->getText()->setString(std::to_string(Level));
    Text->getComponent<RenderText>()->getText()->setString(Name + " | " + std::to_string(cost));
    Gold->getComponent<RenderText>()->getText()->setString(std::to_string(SaveWriter::getInstance()->readGold()));
    
    ButtonMinus->update(dt);
    ButtonPlus->update(dt);
    Bar->update(dt);
    
    if (ButtonMinus->getComponent<ButtonComponent>()->clicked()) {
        Level -= 1;
        if (Level <= 0) {
            Level = 1;
        }
    }
    if (ButtonPlus->getComponent<ButtonComponent>()->clicked()) {
        if (SaveWriter::getInstance()->readGold() >= cost) {
            Level += 1;
            if (Level > MaxLevel) {
                Level = MaxLevel;
            }
            else {
                SaveWriter::getInstance()->writeGold(-cost);
            }
        }
    }
    
    cost = (Level * 1.15) * 50;
}

void StatUpgrade::render() {
    ButtonMinus->render();
    ButtonPlus->render();
    Bar->render();
    Text->render();
    Gold->render();
}

