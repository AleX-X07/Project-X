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
        if (SaveWriter::getInstance()->getCapaUnlock()[key] != true) {
            w->addComponent(new RenderColor(w,{0,0,0,155}));
            w->addComponent(new RenderText(w,"Assets/Font/Brown Cookies.otf"));
            w->getComponent<RenderText>()->setText(std::to_string(CapacityReader::getInstance()->getCapacityPrice()[key]));
        }
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
    myChoices.clear();

    delete buying;
    buying = nullptr;
}

void SpellChoiceComponent::buy(Object* _c) {
    int gold = SaveWriter::getInstance()->readGold();
    int priceC = CapacityReader::getInstance()->getCapacityPrice()[_c->getName()];

    if (gold >= priceC) {
        SaveWriter::getInstance()->writeGold(-priceC);
        SaveWriter::getInstance()->getCapaUnlock()[_c->getName()] = true;
        SaveWriter::getInstance()->writeCapa();

        _c->getComponent<RenderColor>()->getColor() = {0,0,0,0};
        if (_c->getComponent<RenderText>()) {
            _c->getComponent<RenderText>()->setText("");
        }

        delete buying;
        buying = nullptr;
        notMoney = false;
    }
    else {
        buying->getComponent<RenderColor>()->getColor() = sf::Color::Red;
        notMoney = true;
        timer = 0;
    }
}

void SpellChoiceComponent::update(float deltaTime) {
    for (auto& c : capacity) {
        if (c->getComponent<MouseComponent>()->isClick()) {

            bool unlocked = SaveWriter::getInstance()->getCapaUnlock()[c->getName()];

            if (!unlocked) {
                if (buying != nullptr) {
                    delete buying;
                    buying = nullptr;
                }
                buying = new Object();
                buying->setSize({100,100});
                buying->setPosition({1920/2 - buying->getSize().x/2, 980});
                buying->addComponent(new RenderColor(buying,{0,255,0}));
                buying->addComponent(new MouseComponent(buying));
                currentC = c;
            }
            else {
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

    if (buying != nullptr && buying->getComponent<MouseComponent>()->isClick()) {
        buy(currentC);
    }

    if (notMoney && buying != nullptr) {
        timer += deltaTime;
        if (timer > 3.f) {
            timer = 0;
            notMoney = false;
            delete buying;
            buying = nullptr;
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
    if (buying != nullptr) {
        buying->render();
    }
}