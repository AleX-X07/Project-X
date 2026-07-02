#pragma once
#include "../../Object.h"

class GameEngine;

class StatUpgrade {
public:
    int Level;
    int MaxLevel;
    
    int cost;
    
    int id;
    
    Object* ButtonPlus;
    Object* ButtonMinus;
    
    Object* Bar;
    Object* Text;
    
    std::string Name;
    
    Object* Gold;
    
public:
    StatUpgrade(int _Level, float _MaxLevel, int _id, std::string name);
    ~StatUpgrade();
    
    void update(float dt);
    void render();
};
