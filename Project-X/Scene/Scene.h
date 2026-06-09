#pragma once
#include <vector>
#include "../ECS/Object.h"
#include "Layer.h"

class GameEngine;
class HealthComponent;

class Scene {
public:
    Layer myLayer;
    std::vector<Object*> myObjects;
    int idScene;
    
public:
    Scene(int _idScene);
    ~Scene();
    
    Layer& getMyLayer();
    std::vector<Object*>& getVecObjects();
    int getIdScene();
    
    void addObject(Object* addObject, int Layer);
    
    void setLayer(int Layer);
    
    void update(float deltatime);
    void render();
};
