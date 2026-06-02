#pragma once
#include "SFML/Graphics.hpp"

class Object;

class Animation {
public:
    sf::Texture* texture;
    Object* owner;
    
public:
    
    Animation(Object* _owner, const char* path);
    ~Animation() = default;
    
    void update(float deltaTime);
    void render();
};
