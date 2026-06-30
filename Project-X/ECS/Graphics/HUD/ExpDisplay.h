#pragma once
#include "../../Component.h"

class Object;
class HealthComponent;
class GameEngine;
class RenderText;

class ExpDisplay : public Component {
private:
    Object* displayEXP;
    Object* EmptyBar;
    int EXP;
    
    float barsize;
    
public:
    ExpDisplay(Object* _owner, sf::Vector2f pos, sf::Vector2f size, sf::Color color, std::string file);
    ExpDisplay(Object* _owner, sf::Vector2f pos, int size, sf::Color color, std::string font);
    virtual ~ExpDisplay() override;
    
    virtual void update(float dt) override;
    virtual void render() override;
};