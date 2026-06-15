#pragma once
#include <vector>
#include "../ECS/Object.h"
#include "Layer.h"

class GameEngine;
class HealthComponent;
class SceneReader;

class Scene {
public:
    enum class State {
        Run,
        Paused,
    };
private:
    Layer myLayer;
    std::vector<Object*> myObjects;
    int idScene;
    
    State state;
    
    std::string screen;
    
public:
    Scene();
    Scene(int _idScene);
    ~Scene();
    
    Layer& getMyLayer();
    std::vector<Object*>& getVecObjects();
    
    int& getIdScene();
    State& getState();
    
    void addObject(Object* addObject, int Layer);
    
    void setIdScene(int _idScene);
    void setState(State newState);
    void setScreen(std::string newScreen);
    void setLayer(int Layer);
    
    void update(float deltatime);
    void render();
};
