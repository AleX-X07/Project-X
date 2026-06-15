#pragma once
#include "../CapacityMain.h"

class CA_Heal : public CapacityMain {
public:
    float Amount;
    float Interval;
    float Timer;
    
    float ActualTIme = 0;
    float TotalTime = 0;
    
    bool IsActived = false;
public:
    CA_Heal(Object* _owner, float _Amount, float _Interval, float _Timer, float _CoolDown);
    ~CA_Heal() override = default;
    
    void update(float dt) override;
    
    void activate() override;
    void Heal();
};
