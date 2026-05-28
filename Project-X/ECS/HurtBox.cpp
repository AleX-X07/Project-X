#include "HurtBox.h"

#include "BulletManager.h"

HurtBox::HurtBox(Object* _owner, sf::Vector2f _size, std::vector<Object*>& _objects )
    : Component(_owner), other(_objects)
{
    size = _size;
}

void HurtBox::update(float dt)
{
    pos = owner->getPosition();
    intersect();
}

void HurtBox::render()
{

}

bool HurtBox::intersect()
{
    for (auto b : other)
    {
        if (b->getComponent<HurtBox>() != this) {
            auto comp = b->getComponent<BulletManager>();
            if (comp != nullptr) {
                for (auto c : comp->bullet)
                {
                    auto z = c->getComponent<HitBox>();
                    if (z != nullptr)
                    {
                        if (
                    z->pos.x < pos.x + size.x &&
                    z->pos.x + z->size.x > pos.x &&
                    z->pos.y < pos.y + size.y &&
                    z->pos.y + z->size.y > pos.y
                    )
                        {
                            comp->bullet.erase(std::find(comp->bullet.begin(), comp->bullet.end(), c));
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}
