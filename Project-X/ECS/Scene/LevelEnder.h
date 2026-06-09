#pragma once
#include "../Object.h"

class LevelEnder : public Component {
public:
 
    bool HasEnd;

public:
    LevelEnder(Object* owner, float _Timer);
    ~LevelEnder() override;
    
    void update(float deltaTime) override;
    void render() override;
};
