#include "HitBox.h"

HitBox::HitBox(Object* _owner, sf::Vector2f _size)
    : Component(_owner)
{
    size = _size;
}

void HitBox::update(float dt)
{
    pos = owner->getPosition();
}

void HitBox::render()
{

}
