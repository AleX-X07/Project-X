#include "HitBox.h"

HitBox::HitBox(Object* _owner, sf::Vector2f _size, bool _isactive, int _damage)
    : Component(_owner)
{
    size = _size;
    isactive = _isactive;
    damage = _damage;
}

void HitBox::update(float dt)
{
    pos = owner->getPosition();
}

void HitBox::render()
{

}
