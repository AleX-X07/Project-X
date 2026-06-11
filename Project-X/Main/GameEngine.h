#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include <unordered_map>

#include "../Scene/Scene.h"
#include "../Reader/SceneReader.h"
#include "../Reader/InputReader.h"
#include "../Reader/WeaponReader.h"

class GameEngine {
private:
    
    static sf::RenderWindow* window;
    
    static std::unordered_map<int, Scene*> scenes;
    static std::unordered_map<int, Scene*> scenesPaused;
    
    std::vector<Reader*> readers;
    
    static int idScene;
    static int idScenePaused;
    
    sf::Clock clock;
    float delatTime;
    bool inGame;
    
    void initRead();
    void readData();
    
    void updateEvent();
    void updateTime();
    void update();
    void render();
    
public:
    
    static sf::RenderWindow* getWindow();
    static std::unordered_map<int, Scene*>& getVecState();
    static std::unordered_map<int, Scene*>& getVecPaused();
    
    static void setScene(int newScene);
    static void setScenePaused(int newScene);
    
    static int getIdCurrentScenePaused();
    static int getIdCurrentScene();
    
    GameEngine();
    ~GameEngine();
    void run();
    
};

