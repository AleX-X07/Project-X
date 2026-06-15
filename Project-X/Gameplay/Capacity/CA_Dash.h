#pragma once

#include "../CapacityMain.h"

class CA_Dash : public CapacityMain {
public:
    float distance;
    float speed;

    float ActualTIme = 0;
    
    float Angle;
    
    sf::Vector2f objectivePos;
    
    bool IsActived = false;
public:
    CA_Dash(Object* _owner, float _speed, float _distance, float _Cooldown);
    ~CA_Dash() override = default;

    void update(float dt) override;

    void activate() override;
    void levelUp() override;
};

