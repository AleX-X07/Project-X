#include "ExpManager.h"
#include "../../../Main/GameEngine.h"

#include "../../../Gameplay/CapacityManager.h"

ExpManager::ExpManager(Object* _owner) : Component(_owner) {
    winSize = GameEngine::getWindow()->getSize();
    
    rect.setSize({static_cast<float>(winSize.x),10});
    rect.setPosition({0, (static_cast<float>(winSize.y)-10)});
    bar.setSize({0, 10});
    bar.setPosition({0, (static_cast<float>(winSize.y)-10)});
    
    rect.setFillColor(sf::Color::Black);
    bar.setFillColor(sf::Color::Blue);
    
    if (!myFont.openFromFile("Assets/Font/Brown Cookies.otf")) {
        std::cerr << "Erreur : impossible de charger la police !" << std::endl;
    }
    myText = new sf::Text(myFont);
    
    myText->setPosition({static_cast<float>(winSize.x) / 2, static_cast<float>(winSize.y) - 40});
    myText->setCharacterSize(24);
}

ExpManager::~ExpManager() {
    delete myText;
    myText = nullptr;
}

void ExpManager::update(float deltaTime) {
    auto comp = owner->getComponent<CapacityManager>();
    
    float fill = (Exp / comp->ExpNeed) * static_cast<float>(winSize.x);
    bar.setSize({fill, 25});
    
    std::string text = "Level " + std::to_string(level);
    myText->setString(text);
}

float ExpManager::getExp() {
    return Exp;
}

void ExpManager::setExp(int _exp) {
    Exp = _exp;
}

void ExpManager::render() {
    /*
    GameEngine::getWindow()->setView(GameEngine::getWindow()->getDefaultView());
    GameEngine::getWindow()->draw(rect);
    GameEngine::getWindow()->draw(bar);
    GameEngine::getWindow()->draw(*myText);
    
    auto cam = owner->getComponent<CameraComponent>();
    if (cam != nullptr)
    {
        GameEngine::getWindow()->setView(*cam->view);
    }
    */
}


