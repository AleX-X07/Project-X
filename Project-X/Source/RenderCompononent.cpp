#include "RenderCompononent.h"

RenderCompononent::RenderCompononent(Object* _owner, std::string name) : Component(_owner)
{
    setTexture(name);
    Rect.setPosition(owner->getPosition());
    Rect.setSize({owner->getSize().x, owner->getSize().y});
}

void RenderCompononent::update(float deltaTime)
{
    Rect.setPosition(owner->getPosition());
    if (texture.getSize().x > 0 && texture.getSize().y > 0)
    {
        Rect.setScale({owner->getSize().x / texture.getSize().x,
                       owner->getSize().y / texture.getSize().y});
    }
}

void RenderCompononent::render(sf::RenderWindow& window)
{
    window.draw(Rect);
}

void RenderCompononent::setTexture(std::string _name)
{
    texture.loadFromFile(_name);
    Rect.setTexture(&texture);
}