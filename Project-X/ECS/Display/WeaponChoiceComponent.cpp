#include "WeaponChoiceComponent.h"
#include  "../../Main/GameEngine.h"

WeaponChoiceComponent::WeaponChoiceComponent(Object* _owner, Scene* currentScene) : Component(_owner){
    myChoices = nullptr;
    sf::Vector2f Size = {150,150};
    int ligne = 6;
    int col = 0;
    int row = 0;
    
    float marginX = 200; 
    float marginY = 100; 
    
    float padding = 100;

    for (auto& [key, value] : WeaponReader::getWeapons()) {
        sf::Vector2f Pos = {
            (Size.x + padding) * col + marginX,
            (Size.y + padding) * row + marginY
        };

        Object* w = new Object(Pos, Size);
        w->setName(key);
        w->addComponent(new MouseComponent(w));
        w->addComponent(new RenderFile(w, value.WeaponImage));
        weapons.push_back(w);
        
        col++;
        if (col >= ligne) {
            col = 0;
            row++;
        }
    }
}

WeaponChoiceComponent::~WeaponChoiceComponent() {
    delete myChoices;
    myChoices = nullptr;
    
    for (auto& w : weapons) {
        delete w;
        w = nullptr;
    }
    weapons.clear();
}

void WeaponChoiceComponent::update(float deltaTime) {
    for (auto& w : weapons) {
        if (w->getComponent<MouseComponent>()->isClick()) {
            GameEngine::myWeapon = nullptr;
            if (myChoices != nullptr) {
                delete myChoices;
                myChoices = nullptr;
            }
            myChoices = new sf::RectangleShape(w->getSize());
            myChoices->setPosition(w->getPosition());
            myChoices->setFillColor(sf::Color::Transparent);
            myChoices->setOutlineColor(sf::Color::Green);
            myChoices->setOutlineThickness(2.f);
            GameEngine::myWeapon = new std::string(w->getName());
        }
    }
}

void WeaponChoiceComponent::render() {
    for (auto& w : weapons) {
        w->render();
    }
    if (myChoices != nullptr) {
        GameEngine::getWindow()->draw(*myChoices);
    }
}


