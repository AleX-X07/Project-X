#pragma once
#include "../CapacityMain.h"

class CA_Tank : public CapacityMain {
public:
    float Timer;
    
    float ActualTIme = 0;
    float TotalTime = 0;
    
    bool IsActived = false;
    
    float speedModifier;
    float StoredSpeed;
    
    sf::RectangleShape rect;
    sf::Texture TX;

public:
    CA_Tank(Object* _owner, float _Timer, float _CoolDown, int _Button);
    ~CA_Tank() override = default;
    
    void update(float dt) override;
    void render() override;
    
    void activate() override;
    void levelUp() override;
};

