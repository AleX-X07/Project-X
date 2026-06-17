#pragma once
#include "../ElementMain.h"

class CH_Fire : public ElementMain {
public:
    float interval;
    float TimerActualTime = 0;
    
    float damage;
    
public:
    CH_Fire(ChemicalManager& _Manager, float _duration, float _damage, float _interval);
    ~CH_Fire() override = default;
    
    void update(float dt) override;
};
