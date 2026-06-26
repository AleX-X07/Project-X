#pragma once
#include "../CapacityMain.h"

class CA_Lightning : public CapacityMain {
public:
    float Timer;
    
    float ActualTIme = 0;
    float TotalTime = 0;
    
    bool IsActived = false;
public:
    CA_Lightning(Object* _owner, float _Timer, float _CoolDown, int _Button);
    ~CA_Lightning() override = default;
    
    void update(float dt) override;
    
    void activate() override;
    void levelUp() override;
};

