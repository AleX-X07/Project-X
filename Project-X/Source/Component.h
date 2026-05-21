#pragma once
#include <SFML/Graphics.hpp>

class gameObject;

class Component
{
protected:
    gameObject* owner;

public:
    Component(gameObject* _owner);
    virtual ~Component() = default;

    virtual void update(float deltaTime);
    virtual void render(sf::RenderWindow& window);
};