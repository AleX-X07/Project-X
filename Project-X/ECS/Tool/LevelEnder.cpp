#include "LevelEnder.h"
#include "../../Main/GameEngine.h"

LevelEnder::LevelEnder(Object* _owner, float _Timer) : Component(_owner) {
    Timer = _Timer;
    
    if (!font.openFromFile("Assets/Font/Brown Cookies.otf")) {
        std::cerr << "Erreur : impossible de charger la police !" << std::endl;
    }
    text = new sf::Text(font);
    text->setPosition({500, 0});
    text->setCharacterSize(24);
    text->setFillColor(sf::Color::White);
}

LevelEnder::~LevelEnder() {
    delete text;
    text = nullptr;
}

void LevelEnder::update(float deltaTime) {
    ActualTime += deltaTime;
    
    if (ActualTime >= Timer) {
        HasEnd = true;
    }
    
    int TextTimer = Timer - ActualTime;
    text->setString(std::to_string(TextTimer));
}

void LevelEnder::render() {
    GameEngine::getWindow()->setView(GameEngine::getWindow()->getDefaultView());
    GameEngine::getWindow()->draw(*text);
    
    auto cam = owner->getComponent<CameraComponent>();
    if (cam != nullptr)
    {
        GameEngine::getWindow()->setView(*cam->view);
    }
}
