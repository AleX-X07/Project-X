#pragma once
#include "../CapacityMain.h"

class CA_Rage : public CapacityMain {
public:
    float Timer;
    
    float ActualTIme = 0;
    float TotalTime = 0;
    
    bool IsActived = false;
    
    float RageSpread = 2;
    float RageDamage = 2;

public:
    CA_Rage(Object* _owner, float _Timer, float _CoolDown);
    ~CA_Rage() override = default;
    
    void update(float dt) override;
    
    void activate() override;
    void levelUp() override;
};
