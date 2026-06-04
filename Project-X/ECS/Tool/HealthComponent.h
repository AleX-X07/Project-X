#pragma once
#include "../Object.h"

class GameEngine;

class HealthComponent final : public Component
{
public:
    int hp;
    int MaxHp;
    
    bool alive = true;
    
    std::vector<Object*>& sceneObjects;

public:
    HealthComponent(Object* _owner, int _MaxHp, std::vector<Object*>& _sceneObjects);
    ~HealthComponent();
    void TakeDamage(int damage);
    
    int getHp();
    
    void Death();
};