#pragma once
#include "../../Object.h"
#include "../../../Tool/Globals.h"
#include "StatUpgrade.h"

class GameEngine;

class StatMenu : public Component
{
public:
    float SpeedLevel;
    float DamageLevel;
    float ExpLevel;
    float GoldLevel;
    float HealthLevel;

    std::vector<Object*>& other;
    StatUpgrade* Health;
    StatUpgrade* Speed;
    StatUpgrade* Damage;
    StatUpgrade* ExpBoost;
    StatUpgrade* GoldBoost;
    
public:
    StatMenu(Object* _owner, std::vector<Object*>& _objects);
    ~StatMenu() override;
    
    void update(float deltaTime) override;
    void render() override;
    
    void save();
};