#include "DebugHudComp.h"

#include "../../../Main/GameEngine.h"

DebugHudComp::DebugHudComp(Object* _owner) : Component(_owner)
{
    font.openFromFile("Assets/Font/Brown Cookies.otf");
    Hp = new sf::Text(font);
    Hp->setPosition({0, 0});
    Hp->setCharacterSize(24);
    Hp->setFillColor(sf::Color::White);
    
    Exp = new sf::Text(font);
    Exp->setPosition({0, 25});
    Exp->setCharacterSize(24);
    Exp->setFillColor(sf::Color::White);
}

DebugHudComp::~DebugHudComp()
{
    delete Hp;
    delete Exp;
    
    Hp = nullptr;
    Exp = nullptr;
}

void DebugHudComp::update(float deltaTime)
{
    auto health = owner->getComponent<HealthComponent>();
    if (health != nullptr)
    {
        Hp->setString((std::to_string(health->hp)));
    }
    else
    {
        Hp->setString("None");
    }
    
    auto Experience = owner->getComponent<ExpManager>();
    if (Experience != nullptr)
    {
        Exp->setString((std::to_string(Experience->Exp)));
    }
    else
    {
        Exp->setString("None");
    }
}

void DebugHudComp::render()
{
    GameEngine::getWindow()->setView(GameEngine::getWindow()->getDefaultView());
    GameEngine::getWindow()->draw(*Hp);
    GameEngine::getWindow()->draw(*Exp);
    
    auto cam = owner->getComponent<CameraComponent>();
    if (cam != nullptr)
    {
        GameEngine::getWindow()->setView(*cam->view);
    }
}
