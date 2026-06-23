#pragma once
#include "../ElementMain.h"

class CH_Poison : public ElementMain {
public:
    float interval;
    float TimerActualTime = 0;
    
    float damage;
    
public:
    CH_Poison(ChemicalManager& _Manager, float _duration, float _damage, float _interval);
    ~CH_Poison() override = default;
    
    void update(float dt) override;
};
