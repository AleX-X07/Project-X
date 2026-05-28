#pragma once
#include "../Object.h"


class HitBox : public Component
{
public:
    
    sf::Vector2f pos;
    sf::Vector2f size;
    
    sf::RectangleShape rect;
    
public:
    HitBox(Object* _owner, sf::Vector2f _size);
    ~HitBox() override = default;
    
    void update(float dt) override;
    void render() override;
};