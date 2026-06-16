#pragma once
#include "../Object.h"

class HealthBar : public Component{
public:
    sf::RectangleShape fill;
    sf::RectangleShape bar;
    
    sf::Vector2f pos;
    sf::Vector2f size;
    
public:
    HealthBar(Object* _owner, sf::Color color);
    ~HealthBar() override;
    
    void update(float deltaTime) override;
    void render() override;
};
