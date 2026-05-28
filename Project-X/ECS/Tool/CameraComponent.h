#pragma once

#include "../Object.h"

class GameEngine;

class CameraComponent final : public Component
{
private:
    sf::RectangleShape sizeC;
    sf::Vector2f ScreenSize;
    sf::Vector2f LevelSize;

    sf::Vector2f pos;
    sf::Vector2f ObjectivePos;
    sf::Vector2f LagPos;
    
    float lag;
    bool haslag;

    sf::Vector2f worldPos;
    sf::Vector2f worldSize;

    sf::View* view;

    sf::Vector2f CamPos;

public:
    CameraComponent(Object* _owner, float ScreenX, float ScreenY, float LevelX, float LevelY, bool _hasLag, float lagfactor);
    ~CameraComponent() override;

    void update(float deltaTime) override;
};