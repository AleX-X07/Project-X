#pragma once
#include "../Object.h"

class GameEngine;

class HealthComponent final : public Component
{
public:
    int hp;
    int MaxHp;
    
    bool alive = true;

public:
    HealthComponent(Object* _owner, int _MaxHp);
    ~HealthComponent();
    
    //void update(float deltaTime) override;
    void TakeDamage(int damage);
    
    int getHp();
    
    //void AddDeathComponent(Component* DeathComp);
    void Death();
};