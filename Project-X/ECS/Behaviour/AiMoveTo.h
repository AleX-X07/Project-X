#pragma once
#include "../Object.h"
#include "../Bullet/BulletManager.h"

class GameEngine;

class AiMoveTo : public Component
{
public:
    
    float speed;
    
    Object* target;
    std::vector<Object*>& other;
    
    sf::Vector2f actualPos;
    
public:
    AiMoveTo(Object* _owner, std::vector<Object*>& _objects, float _speed);
    ~AiMoveTo() override;
    
    void update(float dt) override;
};
