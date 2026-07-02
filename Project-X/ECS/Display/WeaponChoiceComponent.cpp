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
        if (SaveWriter::getInstance()->getWeaponUnlock()[key] != true) {
            w->addComponent(new RenderColor(w,{0,0,0,155}));
            w->addComponent(new RenderText(w,"Assets/Font/Brown Cookies.otf"));
            w->getComponent<RenderText>()->setText(std::to_string(value.price));
        }
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

void WeaponChoiceComponent::buy(Object* _w) {
    int gold = SaveWriter::getInstance()->readGold();
    int priceW = WeaponReader::getInstance()->getWeapons()[_w->getName()].price;
    if (gold >= priceW) {
        SaveWriter::getInstance()->writeGold(-priceW);
        SaveWriter::getInstance()->getWeaponUnlock()[_w->getName()] = true;
        SaveWriter::getInstance()->writeWeapon();
        _w->getComponent<RenderColor>()->getColor() = {0,0,0,0};
        GameEngine::myWeapon = new std::string(_w->getName());
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

void WeaponChoiceComponent::update(float deltaTime) {
    for (auto& w : weapons) {
        if (w->getComponent<MouseComponent>()->isClick()) {
            if (buying != nullptr) {
                delete buying;
                buying = nullptr;
            }
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
            if (SaveWriter::getInstance()->getWeaponUnlock()[w->getName()]) {
                GameEngine::myWeapon = new std::string(w->getName());
            }
            else {
                buying = new Object();
                buying->setSize({100,100});
                buying->setPosition({1920/2-buying->getSize().x/2,980});
                buying->addComponent(new RenderColor(buying,{0,255,0}));
                buying->addComponent(new MouseComponent(buying));
            }
            currentW = w;
        }
        w->update(deltaTime);
    }
    if (buying != nullptr && buying->getComponent<MouseComponent>()->isClick()) {
        buy(currentW);
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

void WeaponChoiceComponent::render() {
    for (auto& w : weapons) {
        w->render();
    }
    if (myChoices != nullptr) {
        GameEngine::getWindow()->draw(*myChoices);
    }
    if (buying != nullptr) {
        buying->render();
    }
}


