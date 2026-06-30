#pragma once
#include "../Object.h"

class GameEngine;

class Collider : public Component
{
public:
    
    sf::Vector2f pos;
    sf::Vector2f size;
    
    std::vector<Object*>& other;
    
public:
    //FOR DEBUG
    
    sf::RectangleShape rect;
    sf::Texture TX;

public:
    Collider(Object* _owner, std::vector<Object*>& _objects);
    ~Collider() override = default;
    
    void update(float dt) override;
    void render() override;
    
    bool intersects(Object* object);
    //void collisionHori(Object* object);
    //void collisionVert(Object* object);
    
    void resolveCollision(Object* object);
};