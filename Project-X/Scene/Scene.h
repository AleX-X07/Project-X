#pragma once
#include <vector>
#include "../ECS/Object.h"
#include "Layer.h"

class Scene {
private:
    Layer myLayer;
    std::vector<Object*> myObjects;
    int idScene;
    
public:
    Scene(int _idScene);
    ~Scene() = default;
    
    Layer& getMyLayer();
    std::vector<Object*>& getVecObjects();

    void addObject(Object* addObject, int Layer);
    
    void setLayer(int Layer);
    void update(float deltatime);
    void render();
};
