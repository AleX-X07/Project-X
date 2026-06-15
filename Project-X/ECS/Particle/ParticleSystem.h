#pragma once
#include <SFML/Graphics.hpp>

class GameEngine;

class ParticleSystem {
public:
    sf::RectangleShape rect;
    
    sf::Vector2f pos;
    sf::Vector2f size;
    
    float angle;
    float speed;
    
    float lifetime = 0;
    float actualTime = 0;
    bool IsAlive = true;

public:
    ParticleSystem(sf::Vector2f _pos, sf::Vector2f _size, float _angle, float _speed, float _lifetime, sf::Color Color);
    ~ParticleSystem();
    
    void update(float dt);
    void render();
};
