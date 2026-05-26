#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

#include "../Scene/Scene.h"
#include "../Scene/SceneReader.h"

class GameEngine {
private:
    
    static sf::RenderWindow* window;
    static std::vector<Scene*> scenes;
    
    sf::Clock clock;
    float delatTime;
    
    void start();
    
    void updateEvent();
    void updateTime();
    void update();
    void render();
    
public:
    
    static sf::RenderWindow* getWindow();
    static std::vector<Scene*> getVecState();
    
    GameEngine();
    ~GameEngine();
    void run();
    
};

