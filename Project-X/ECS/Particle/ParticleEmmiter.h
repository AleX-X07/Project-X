#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "ParticleSystem.h"

class ParticleEmmiter {
public:
    std::vector<std::unique_ptr<ParticleSystem>> ParticleList;
    
    sf::Vector2f pos;
    sf::Vector2f size;
    
    float lifetime;
    
    int quantity;
    int burstquantity;
    
    bool isAlive = true;
    
public:
    ParticleEmmiter(sf::Vector2f _pos, sf::Vector2f _size, int _quantity, int _burstquantity);
    ~ParticleEmmiter();
    
    void update(float deltaTime);
    void render();
    
    void Burst();
};
