#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

#include "../Scene/Scene.h"
#include "../Reader/SceneReader.h"
#include "../Reader/InputReader.h"
#include "../Reader/WeaponReader.h"

class GameEngine {
private:
    
    static sf::RenderWindow* window;
    static std::vector<Scene*> scenes;
    
    static int idScene;
    
    sf::Clock clock;
    float delatTime;
    
    void start();
    
    void updateEvent();
    void updateTime();
    void update();
    void render();
    
public:
    
    static sf::RenderWindow* getWindow();
    static std::vector<Scene*>& getVecState();
    static void setScene(int newScene);
    static int getIdCurrentScene();
    
    GameEngine();
    ~GameEngine();
    void run();
    
};

