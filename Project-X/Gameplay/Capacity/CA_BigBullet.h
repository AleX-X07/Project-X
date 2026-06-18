#pragma once
#include "../CapacityMain.h"

class CA_bigbullet : public CapacityMain {
public:
    float Multi;
    
    float ActualTIme = 0;
    float TotalTime = 0;
    
    bool IsActived = false;
    bool stored;
public:
    CA_bigbullet(Object* _owner, float _Multi, float _CoolDown);
    ~CA_bigbullet() override = default;
    
    void update(float dt) override;
    
    void activate() override;
    
    void levelUp() override;
};
