#pragma once
#include "../ECS/Object.h"
#include "CapacityMain.h"
#include "../Pattern/GamepadType.h"
#include "Test/CapaButton.h"

class GameEngine;

class CapacityManager : public Component{
public:
    AxisMapping mapping;
    
    sf::Vector2u winSize;
    
    CapacityMain* ActualCapa;
    CapacityMain* SecondaryCapa;
    CapacityMain* UltiCapa;
    
    std::vector<CapaButton> buttonList;
    
    bool pending = false;
    
    float ExpNeed = 10;
    float ExpMulti = 1.2f;
    
    int pendnumber;
    
    bool offered = false;
public:
    CapacityManager(Object* _owner);
    ~CapacityManager();
    
    void update(float deltaTime) override;
    void render() override;
    
    void offerUpgrade(CapacityMain* capa);
};
