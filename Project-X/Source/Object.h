#pragma once

#include "SFML/Graphics.hpp"
#include "Component.h"

class gameObject
{
private:
    sf::Vector2f position;
    sf::Vector2f size;
    std::vector<Component*> components = {};

public:
    gameObject(sf::Vector2f _position, sf::Vector2f _size);
    ~gameObject();

    void update(float deltaTime);
    void render(sf::RenderWindow& window);

    void addComponent(Component* newComponent);

    template <typename T> T* getComponent()
    {
        for (auto comp : components)
        {
            auto* downcastComponent = dynamic_cast<T*>(comp);
            if (downcastComponent != nullptr)
            {
                return downcastComponent;
            }
        }
        return nullptr;
    }

    template <typename T> bool hasComponent()
    {
        for (auto comp : components)
        {
            if (auto downcastComponent = dynamic_cast<T*>(comp); downcastComponent != nullptr)
            {
                return true;
            }
        }
        return false;
    }

    sf::Vector2f getPosition();
    void setPosition(sf::Vector2f newPosition);
    sf::Vector2f getSize();
    void setSize(sf::Vector2f newSize);
};