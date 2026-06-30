#pragma once
#include "../../Component.h"

class Object;
class HealthComponent;
class GameEngine;
class RenderText;

class HealthDisplay : public Component {
private:
    Object* displayHP;
    Object* EmptyBar;
    int HP;
    
    float barsize;
    
public:
    HealthDisplay(Object* _owner, sf::Vector2f pos, sf::Vector2f size, sf::Color color, std::string file);
    HealthDisplay(Object* _owner, sf::Vector2f pos, int size, sf::Color color, std::string font);
    virtual ~HealthDisplay() override;
    
    virtual void update(float dt) override;
    virtual void render() override;
};
