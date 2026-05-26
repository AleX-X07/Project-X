#pragma once
#include <vector>
#include "../ECS/Object.h"
#include "Layer.h"

class Scene {
private:
    Layer myLayer;
    std::vector<Object*> myObjects;
    
public:
    Scene(int nbrLayer);
    ~Scene() = default;
    
    Layer& getMyLayer();
    std::vector<Object*>& getVecObjects();
    
    void update(float deltatime);
    void render();
};
