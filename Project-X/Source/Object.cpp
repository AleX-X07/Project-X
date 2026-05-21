#include "Object.h"

Object::Object(sf::Vector2f _position, sf::Vector2f _size)
    : position(_position)
    , size(_size)
{
}

Object::~Object()
{
    for (auto& comp : components)
    {
        delete comp;
        comp = nullptr;
    }
}

void Object::update(float deltaTime)
{
    for (auto& comp : components)
    {
        comp->update(deltaTime);
    }
}

void Object::render(sf::RenderWindow& window)
{
    for (auto& comp : components)
    {
        comp->render(window);
    }
}

void Object::addComponent(Component* newComponent)
{
    components.push_back(newComponent);
}

sf::Vector2f Object::getPosition()
{
    return position;
}

void Object::setPosition(sf::Vector2f newPosition)
{
    position = newPosition;
}

sf::Vector2f Object::getSize()
{
    return size;
}

void Object::setSize(sf::Vector2f newSize)
{
    size = newSize;
}