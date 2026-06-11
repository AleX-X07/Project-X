#include "RenderColor.h"
#include "../Object.h"
#include "../../Main/GameEngine.h"

RenderColor::RenderColor(Object* _owner) : RenderColor(_owner, {255,255,255,255}){
}

RenderColor::RenderColor(Object* _owner, sf::Color _color) : Component(_owner), color(_color){
    rect.setFillColor(color);
    rect.setPosition(owner->getPosition());
    rect.setSize(owner->getSize());
}

void RenderColor::update(float deltaTime) {
    rect.setPosition(owner->getPosition());
}

void RenderColor::render() {
    rect.setFillColor(color);
    GameEngine::getWindow()->draw(rect);
}

sf::RectangleShape& RenderColor::getRect() {
    return rect;
}

sf::Color& RenderColor::getColor() {
    return color;
}
