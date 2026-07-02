#pragma once

#include "../Object.h"
#include "../../Tool/Globals.h"

class GameEngine;

class ButtonComponent : public Component
{
public:
    sf::Vector2f pos;
    sf::Vector2f size;

    bool click = false;
public:
    ButtonComponent(Object* _owner, sf::Vector2f _pos, sf::Vector2f _size);
    ~ButtonComponent() override = default;

    void update(float deltaTime) override;
    bool clicked();
};