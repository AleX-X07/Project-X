#pragma once

#include "Object.h"

class RenderCompononent final : public Component
{
private:
    sf::Texture texture;
    sf::RectangleShape Rect;

public:
    RenderCompononent(Object* _owner, std::string name);
    ~RenderCompononent() override = default;

    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;
    
    void setTexture(std::string _name);
};
