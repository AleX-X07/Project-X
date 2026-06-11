#pragma once
#include "../Component.h"


class GameEngine;
class Object;

class RenderColor final : public Component {
private:
    sf::RectangleShape rect;
    sf::Color color;
public:
    RenderColor(Object* _owner);
    RenderColor(Object* _owner, sf::Color _color);
    virtual ~RenderColor() override = default;
    
    virtual void update(float deltaTime) override;
    virtual void render() override;
    
    sf::RectangleShape& getRect();
    sf::Color& getColor();
};
