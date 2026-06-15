#pragma once
#include "../CapacityMain.h"

class CA_Frenesie : public CapacityMain {
public:
    float Timer;
    
    float ActualTIme = 0;
    float TotalTime = 0;
    
    bool IsActived = false;
public:
    CA_Frenesie(Object* _owner, float _Timer, float _CoolDown);
    ~CA_Frenesie() override = default;
    
    void update(float dt) override;
    
    void activate() override;
};
