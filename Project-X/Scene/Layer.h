#pragma once
#include <vector>
#include <iostream>
#include <ostream>

#include "../ECS/Object.h"

class Layer {
private:   
    std::vector<std::vector<Object*>> layers;
    int nbrLayers;
    
public:
    Layer() = default;
    ~Layer() = default;
    
    void setNbrLayer(int nbrLayers);
    void addInLayer(Object* myObject, int layer);
    
    void render();
};
