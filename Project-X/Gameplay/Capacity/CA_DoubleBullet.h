#pragma once
#include "../CapacityMain.h"

class CA_DoubleBullet : public CapacityMain {
public:
    float Timer;
    
    float ActualTIme = 0;
    float TotalTime = 0;
    
    bool IsActived = false;
public:
    CA_DoubleBullet(Object* _owner, float _Timer, float _CoolDown);
    ~CA_DoubleBullet() override = default;
    
    void update(float dt) override;
    
    void activate() override;
};
