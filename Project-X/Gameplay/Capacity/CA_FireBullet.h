#pragma once
#include "../CapacityMain.h"

class CA_FireBullet : public CapacityMain {
public:
    float Timer;
    
    float ActualTIme = 0;
    float TotalTime = 0;
    
    bool IsActived = false;
public:
    CA_FireBullet(Object* _owner, float _Timer, float _CoolDown, int _Button);
    ~CA_FireBullet() override = default;
    
    void update(float dt) override;
    
    void activate() override;
    void levelUp() override;
};
