#pragma once
#include "../../Object.h"
#include "SFML/Audio.hpp"
#include "../../../Scene/Layer.h"
#include "../AiMoveTo.h"
#include "../../Tool/Experience/ExperienceContainer.h"
#include "../../Tool/Experience/ExpComponent.h"
#include "../../../Tool/Globals.h"
#include "../../Input/InputComponent.h"

class GameEngine;

class BossManager : public Component {
public:
    float actualtime = 0;
    float rate = 2;
    
    float ActualTimer = 0;
    float Timer;
    
    std::vector<Object*>& sceneObjects;
    bool hasspawn = false;
    
public:
    BossManager(Object* _owner, float _Timer, std::vector<Object*>& _sceneObjects);
    ~BossManager() override;
    
    void update(float deltaTime) override;
    void render() override;
    
    void spawnBoss();
};
