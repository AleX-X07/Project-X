#include "SpellChoiceComponent.h"
#include "../../Main/GameEngine.h"
#include "../../Reader/CapacityReader.h"

SpellChoiceComponent::SpellChoiceComponent(Object* _owner) : Component(_owner){
    sf::Vector2f Size = {150,150};
    int ligne = 6;
    int col = 0;
    int row = 0;
    
    float marginX = 200; 
    float marginY = 100; 
    
    float padding = 100;

    for (auto& [key,value] : CapacityReader::getInstance()->getCapacity()) {
        sf::Vector2f Pos = {
            (Size.x + padding) * col + marginX,
            (Size.y + padding) * row + marginY
        };

        Object* w = new Object(Pos, Size);
        w->setName(key);
        w->addComponent(new MouseComponent(w));
        w->addComponent(new RenderFile(w, value));
        capacity.push_back(w);
        
        col++;
        if (col >= ligne) {
            col = 0;
            row++;
        }
    }
}

SpellChoiceComponent::~SpellChoiceComponent() {
    for (auto& c : capacity) {
        delete c;
        c = nullptr;
    }
    capacity.clear();
    for (auto& c : myChoices) {
        delete c;
        c = nullptr;
    }
}

void SpellChoiceComponent::update(float deltaTime) {
    for (auto& c : capacity) {
        if (c->getComponent<MouseComponent>()->isClick()) {
            if (c->getComponent<MouseComponent>()->isSelected()) {
                if (myChoices.size() <= 2) {
                    sf::RectangleShape* choices = new sf::RectangleShape(c->getSize());
                    choices->setPosition(c->getPosition());
                    choices->setFillColor(sf::Color::Transparent);
                    choices->setOutlineColor(sf::Color::Green);
                    choices->setOutlineThickness(2.f);
                    myChoices.push_back(choices);
                    GameEngine::myCapacity.push_back(c->getName());
                }
                else {
                    std::cerr << "Trop de compétence choisi !" << std::endl;
                }
            }
            else {
                for (int i = 0; i < myChoices.size(); i++) {
                    if (myChoices[i]->getPosition() == c->getPosition()) {
                        delete myChoices[i];
                        myChoices.erase(myChoices.begin() + i);
                        break;
                    }
                }
                for (int i = 0; i < GameEngine::myCapacity.size(); i++) {
                    if (GameEngine::myCapacity[i] == c->getName()) {
                        GameEngine::myCapacity.erase(GameEngine::myCapacity.begin() + i);
                        break;
                    }
                }
            }
        }
    }
}

void SpellChoiceComponent::render() {
    for (auto& c : capacity) {
        c->render();
    }
    if (!myChoices.empty()) {
        for (auto& c : myChoices) {
            GameEngine::getWindow()->draw(*c);
        }
    }
}
