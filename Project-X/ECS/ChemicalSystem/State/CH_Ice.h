#pragma once
#include "../ElementMain.h"

class CH_Ice : public ElementMain {
public:
    float power;
    
public:
    CH_Ice(ChemicalManager& _Manager, float _duration, float _power);
    ~CH_Ice() override = default;
    
    void update(float dt) override;
};
