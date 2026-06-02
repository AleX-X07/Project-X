#include "HurtBox.h"

#include "../Bullet/BulletSystemComponent.h"

HurtBox::HurtBox(Object* _owner, sf::Vector2f _size, std::vector<Object*>& _objects, float _Iframe)
    : Component(_owner), other(_objects)
{
    size = _size;
    Iframe = _Iframe;
}

void HurtBox::update(float dt)
{
    pos = owner->getPosition();
    
    actualtime += dt;
    
    if (intersect())
    {
        auto comp = owner->getComponent<HealthComponent>();
        if (comp != nullptr)
        {
            comp->TakeDamage(damageTaken);
        }
    }
}

void HurtBox::render()
{

}

bool HurtBox::intersect()
{
    for (auto b : other)
    {
        if (b->getComponent<HurtBox>() != this)
        {
            auto hit = b->getComponent<HitBox>();
            if (hit != nullptr)
            {
                if (
                    hit->pos.x < pos.x + size.x &&
                    hit->pos.x + hit->size.x > pos.x &&
                    hit->pos.y < pos.y + size.y &&
                    hit->pos.y + hit->size.y > pos.y
                    )
                {
                    if (actualtime >= Iframe)
                    {
                        damageTaken = 10;
                        actualtime = 0;
                        return true;
                    }
                }
            }
            
            auto comp = b->getComponent<BulletSource>();
            if (comp != nullptr)
            {
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
                            auto* bulletComp = c->getComponent<BulletSystemComponent>();
                            int bulletDamage = (bulletComp != nullptr) ? bulletComp->getDamage() : 0;

                            comp->bullet.erase(std::find(comp->bullet.begin(), comp->bullet.end(), c));
                            if (actualtime >= Iframe)
                            {
                                damageTaken = bulletDamage;
                                actualtime = 0;
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}
