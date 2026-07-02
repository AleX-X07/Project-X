#pragma once
#include "../../Object.h"
#include "../../../Tool/Globals.h"

class GameEngine;

class StatManager final : public Component
{
public:
    int speed;
    int damage;
    int ExpBoost;
    int GoldBoost;
    int Health;

    std::vector<Object*>& other;
    
public:
    StatManager(Object* _owner, std::vector<Object*>& _objects);
    ~StatManager() override;
    
    void load();
};