#pragma once
#include "../../Object.h"

class GameEngine;

class GoldManager : public Component
{
public:
    sf::Vector2u winSize;
    
    int gold = 0;

    sf::Font myFont;
    sf::Text* myText;
    
public:
    GoldManager(Object* _owner);
    ~GoldManager() override;

    void update(float deltaTime) override;
    void render() override;
    
    void setGold(int _gold);
    int getGold();
};
