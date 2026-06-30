#pragma once
#include "../../Component.h"

class Object;
class HealthComponent;
class GameEngine;
class RenderText;

class GoldDisplay : public Component {
private:
    Object* displayGold;
    int Gold;
    
    float barsize;
    
public:
    GoldDisplay(Object* _owner, sf::Vector2f pos, sf::Vector2f size, sf::Color color, std::string file);
    GoldDisplay(Object* _owner, sf::Vector2f pos, int size, sf::Color color, std::string font);
    virtual ~GoldDisplay() override;
    
    virtual void update(float dt) override;
    virtual void render() override;
};
