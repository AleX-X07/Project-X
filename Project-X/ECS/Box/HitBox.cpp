#include "HitBox.h"

HitBox::HitBox(Object* _owner, sf::Vector2f _size, bool _isactive)
    : Component(_owner)
{
    size = _size;
    isactive = _isactive;
}

void HitBox::update(float dt)
{
    pos = owner->getPosition();
}

void HitBox::render()
{

}
