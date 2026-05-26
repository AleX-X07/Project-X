#pragma once
#include <vector>
#include "../Objects/GameObject.h"
#include "Layer.h"

class Scene {
private:
    Layer myLayer;
    std::vector<GameObject*> myObjects;
    
public:
    Scene(int nbrLayer);
    ~Scene() = default;
    
    Layer& getMyLayer();
    std::vector<GameObject*>& getVecObjects();
    
    void update(float deltatime);
    void render();
};
