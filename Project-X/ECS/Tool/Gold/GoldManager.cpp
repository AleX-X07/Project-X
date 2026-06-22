#include "GoldManager.h"
#include "../../../Main/GameEngine.h"

GoldManager::GoldManager(Object* _owner) : Component(_owner) {
    
    if (!myFont.openFromFile("Assets/Font/Brown Cookies.otf")) {
        std::cerr << "Erreur : impossible de charger la police !" << std::endl;
    }
    myText = new sf::Text(myFont);
    
    myText->setPosition({10, 1040});
    myText->setCharacterSize(24);
}

GoldManager::~GoldManager() {
    delete myText;
    myText = nullptr;
}

void GoldManager::update(float deltaTime) {
    myText->setString(std::to_string(gold));
}

int GoldManager::getGold() {
    return gold;
}

void GoldManager::setGold(int _Gold) {
    gold = _Gold;
}

void GoldManager::render() {
    GameEngine::getWindow()->setView(GameEngine::getWindow()->getDefaultView());
    GameEngine::getWindow()->draw(*myText);
    
    auto cam = owner->getComponent<CameraComponent>();
    if (cam != nullptr)
    {
        GameEngine::getWindow()->setView(*cam->view);
    }
}
