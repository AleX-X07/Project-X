#pragma once
#include <vector>
#include "../ECS/Object.h"
#include "Layer.h"

class GameEngine;
class HealthComponent;
class SceneReader;
class Object;

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
    
    std::vector<std::string> screenVec;
    std::vector<Object*>* objectsScreen;
    std::string screen;
    
    State state;

public:
    Scene();
    Scene(int _idScene);
    ~Scene();
    
    Layer& getMyLayer();
    std::vector<Object*>& getVecObjects();
    
    std::vector<std::string>& getScreenVec();
    int& getIdScene();
    State& getState();
    
    void addObject(Object* addObject, int Layer);
    
    void setIdScene(int _idScene);
    void setState(State newState);
    void setScreen(std::string newScreen);
    void clearScreen();
    void setLayer(int Layer);
    
    void update(float deltatime);
    void render();
};
