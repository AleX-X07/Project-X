#include "HitBox.h"

HitBox::HitBox(Object* _owner, int _id, sf::Vector2f _size)
    : Component(_owner)
{
    id = _id;
    size = _size;
}

void HitBox::update(float dt)
{
    pos = owner->getPosition();
}

void HitBox::render()
{

}
