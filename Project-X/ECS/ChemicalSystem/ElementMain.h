#pragma once
#include <string>

class ChemicalManager;

class ElementMain {
public:
    float duration;
    float actualtime = 0;
    
    bool isactive = true;
    
    ChemicalManager& Manager;
    
    std::string file;
public:
    ElementMain(ChemicalManager& _Manager, float _duration);
    virtual ~ElementMain();
    
    virtual void update(float dt);
};
