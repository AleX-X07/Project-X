#pragma once
#include "../ECS/Object.h"
#include "CapacityMain.h"

class CapacityManager : public Component{
public:
    CapacityMain* ActualCapa;
    CapacityMain* SecondaryCapa;
    CapacityMain* UltiCapa;
public:
    CapacityManager(Object* _owner);
    ~CapacityManager();
    
    void update(float deltaTime) override;
    void render() override;
};
