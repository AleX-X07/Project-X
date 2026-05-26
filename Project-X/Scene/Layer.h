#pragma once
#include <vector>
#include <iostream>
#include <ostream>

#include "../Objects/GameObject.h"

class Layer {
private:   
    std::vector<std::vector<GameObject*>> layers;
    int nbrLayers;
    
public:
    Layer() = default;
    ~Layer() = default;
    
    void setNbrLayer(int nbrLayers);
    void addInLayer(GameObject* myObject, int layer);
    
    void render();
};
