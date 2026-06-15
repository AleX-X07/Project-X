#pragma once
#include "../Object.h"
#include "SFML/Audio.hpp"
#include "CameraComponent.h"

class GameEngine;

class LevelEnder : public Component {
public:
    
    float Timer;
    float ActualTime = 0;
    
    bool HasEnd = false;
    
    sf::Font font;
    sf::Text* text;
    
public:
    LevelEnder(Object* owner, float _Timer);
    ~LevelEnder() override;
    
    void update(float deltaTime) override;
    void render() override;
};
