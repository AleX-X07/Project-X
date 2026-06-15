#pragma once
#include "../CapacityMain.h"

class GameEngine;

class CapaButton : public Component {
public:
    sf::RectangleShape rect;
    
    sf::Vector2f pos;
    sf::Vector2f size;
    
    CapacityMain* capa;
public:
    CapaButton(Object* owner, CapacityMain* _capa);
    ~CapaButton();
    
    void update(float dt);
    void render();
    
    void clicked();
};
