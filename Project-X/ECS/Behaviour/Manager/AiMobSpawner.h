#pragma once
#include "../../Object.h"
#include "SFML/Audio.hpp"
#include "../../../Scene/Layer.h"
#include "../AiMoveTo.h"
#include "../../Tool/Experience/ExperienceContainer.h"
#include "../../../Tool/Globals.h"

class GameEngine;

class AiMobSpawner : public Component
{
public:
    std::vector<Object*> liste;
    
    std::vector<Object*>& sceneObjects;
    
    sf::Vector2f LevelSize;
    
    sf::Vector2f ActualPos;
    
    float timer;
    float actualtime = 0;
    
public:
    AiMobSpawner(Object* _owner, std::vector<Object*>& _sceneObjects);
    ~AiMobSpawner() override;
    
    void update(float dt) override;
    void render() override;
    
    void addMob();
    void giveExp();
};