#pragma once
#include <vector>
#include "../ECS/Object.h"
#include "Layer.h"
#include "Transition.h"

class Scene {
private:
    Layer myLayer;
    std::vector<Object*> myObjects;
    std::vector<Transition*> myTransitions;
    int idScene;
    
public:
    Scene(int _idScene);
    ~Scene();
    
    Layer& getMyLayer();
    std::vector<Object*>& getVecObjects();
    std::vector<Transition*>& getVecTransitions();
    int getIdScene();
    
    void addObject(Object* addObject, int Layer);
    void addTransition(Transition* addObject);
    
    void setLayer(int Layer);
    void update(float deltatime);
    void render();
};
