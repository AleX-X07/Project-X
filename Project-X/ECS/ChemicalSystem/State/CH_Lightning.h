#pragma once
#include "../ElementMain.h"

class CH_Lightning : public ElementMain {
public:
    float interval;
    float TimerActualTime = 0;
    
    float damage;
    float storedSpeed;
    
public:
    CH_Lightning(ChemicalManager& _Manager, float _duration, float _damage, float _interval);
    ~CH_Lightning() override = default;
    
    void update(float dt) override;
};
