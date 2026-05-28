#pragma once

#include "../Object.h"
#include "HitBox.h"

#include <iostream>

class HurtBox : public Component
{
private:
    
    sf::Vector2f pos;
    sf::Vector2f size;
    
    sf::RectangleShape rect;
    
    std::vector<Object*>& other;
    
public:
    HurtBox(Object* _owner, sf::Vector2f _size, std::vector<Object*>& _objects );
    ~HurtBox() override = default;
    
    void update(float dt) override;
    void render() override;
    
    bool intersect();
};