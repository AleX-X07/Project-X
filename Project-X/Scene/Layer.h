#pragma once
#include <vector>
#include <iostream>
#include <ostream>

#include "../ECS/Object.h"

class Layer {
private:   
    std::vector<std::vector<Object*>> layers;
    std::vector<Object*> HUD;
    int nbrLayers;
    
public:
    Layer();
    ~Layer() = default;
    
    void setNbrLayer(int nbrLayers);
    void addInLayer(Object* myObject, int layer);
    void addInHUD(Object* myObject);
    
    void render();
};
