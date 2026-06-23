#pragma once

#include "../../Object.h"
#include "../../Tool/Experience/ExpManager.h"
#include "../../Box/HitBox.h"
#include "SFML/Audio.hpp"

#include <iostream>

class GoldComponent : public Component
{
public:
    sf::Vector2f pos;
    sf::Vector2f size;
    sf::RectangleShape rect;
        
    std::vector<Object*>& other;
        
    bool isActive;
    int quantity;

    sf::SoundBuffer buffer;
    sf::Sound* sound;
    
public:
    GoldComponent(Object* _owner, sf::Vector2f _size, std::vector<Object*>& _objects, int _quantity);
    ~GoldComponent() override = default;

    void update(float dt) override;

    void intersect();
    bool overlaps(Object* hit);
};
