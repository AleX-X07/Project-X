#pragma once
#include "../CapacityMain.h"

class CA_IceBullet : public CapacityMain {
public:
    float Timer;
    
    float ActualTIme = 0;
    float TotalTime = 0;
    
    bool IsActived = false;
public:
    CA_IceBullet(Object* _owner, float _Timer, float _CoolDown);
    ~CA_IceBullet() override = default;
    
    void update(float dt) override;
    
    void activate() override;
    void levelUp() override;
};
