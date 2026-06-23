#pragma once
#include "../../Object.h"

class GameEngine;

class ExpManager : public Component
{
public:
    sf::Vector2u winSize;
    
    sf::RectangleShape rect;
    sf::RectangleShape bar;
    
    float Exp = 0;
    int level = 1;

    sf::Font myFont;
    sf::Text* myText;
    
public:
    ExpManager(Object* _owner);
    ~ExpManager() override;

    void update(float deltaTime) override;
    void render() override;
    
    void setExp(int _exp);
    float getExp();
};