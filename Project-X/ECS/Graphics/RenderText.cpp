#include "RenderText.h"

#include "../../Main/GameEngine.h"

RenderText::RenderText(Object* _owner, std::string file) : Component(_owner){
    if (!myFont.openFromFile(file)) {
        std::cerr << "Erreur : impossible de charger la police !" << std::endl;
    }
    myText = new sf::Text(myFont);
}

RenderText::~RenderText() {
    delete myText;
    myText = nullptr;
}

void RenderText::update(float deltaTime) {
    myText->setPosition(owner->getPosition());
}

void RenderText::render() {
    GameEngine::getWindow()->draw(*myText);
}

sf::Text* RenderText::getText() {
    return myText;
}

void RenderText::setText(std::string text) {
    myText->setString(text);
}
