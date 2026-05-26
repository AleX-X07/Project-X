#pragma once

#include "Object.h"

class GameEngine;

class RenderComponent final : public Component
{
private:
    sf::Texture texture;
    sf::RectangleShape Rect;

public:
    RenderComponent(Object* _owner, std::string name);
    ~RenderComponent() override = default;

    void update(float deltaTime) override;
    void render() override;
    
    void setTexture(std::string _name);
};