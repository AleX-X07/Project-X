#include "Object.h"

gameObject::gameObject(sf::Vector2f _position, sf::Vector2f _size)
    : position(_position)
    , size(_size)
{
}

gameObject::~gameObject()
{
    for (auto& comp : components)
    {
        delete comp;
        comp = nullptr;
    }
}

void gameObject::update(float deltaTime)
{
    for (auto& comp : components)
    {
        comp->update(deltaTime);
    }
}

void gameObject::render(sf::RenderWindow& window)
{
    for (auto& comp : components)
    {
        comp->render(window);
    }
}

void gameObject::addComponent(Component* newComponent)
{
    components.push_back(newComponent);
}

sf::Vector2f gameObject::getPosition()
{
    return position;
}

void gameObject::setPosition(sf::Vector2f newPosition)
{
    position = newPosition;
}

sf::Vector2f gameObject::getSize()
{
    return size;
}

void gameObject::setSize(sf::Vector2f newSize)
{
    size = newSize;
}