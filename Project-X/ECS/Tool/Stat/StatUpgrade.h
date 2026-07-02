#pragma once
#include "../../Object.h"

class GameEngine;

class StatUpgrade {
public:
    int Level;
    int MaxLevel;
    
    float cost;
    
    int id;
    
    Object* ButtonPlus;
    Object* ButtonMinus;
    
    Object* Bar;
    
public:
    StatUpgrade(int _Level, float _MaxLevel, int _id);
    ~StatUpgrade();
    
    void update(float dt);
    void render();
};
