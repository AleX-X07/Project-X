#pragma once
#include "Object.h"


class HitBox : public Component
{
public:
    
    sf::Vector2f pos;
    sf::Vector2f size;
    
    int id;
    
    sf::RectangleShape rect;
    
public:
    HitBox(Object* _owner, int _id, sf::Vector2f _size);
    ~HitBox() override = default;
    
    void update(float dt) override;
    void render() override;
};