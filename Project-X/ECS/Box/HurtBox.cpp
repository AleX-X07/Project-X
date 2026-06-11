#include "HurtBox.h"
#include "../Bullet/BulletLogic/BulletSystemComponent.h"
#include "../Bullet/BulletLogic/GrenadeSystemComponent.h"

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
            comp->TakeDamage(damageTaken);
    }
}

void HurtBox::render() {}

bool HurtBox::overlaps(HitBox* hit)
{
    return hit->pos.x < pos.x + size.x &&
           hit->pos.x + hit->size.x > pos.x &&
           hit->pos.y < pos.y + size.y &&
           hit->pos.y + hit->size.y > pos.y;
}

bool HurtBox::checkHitBox(Object* b)
{
    auto hit = b->getComponent<HitBox>();
    if (!hit || !overlaps(hit)) return false;

    if (actualtime >= Iframe)
    {
        damageTaken = hit->damage;
        actualtime = 0;
        return true;
    }
    return false;
}

bool HurtBox::checkBullets(Object* b)
{
    auto comp = b->getComponent<BulletSource>();
    if (comp && checkBulletsInSource(comp)) return true;
    
    auto spawner = b->getComponent<AiMobSpawner>();
    if (spawner)
    {
        for (auto mob : spawner->liste)
        {
            auto mobComp = mob->getComponent<BulletSource>();
            if (mobComp && checkBulletsInSource(mobComp)) return true;
        }
    }

    return false;
}

bool HurtBox::checkBulletsInSource(BulletSource* comp)
{
    for (auto it = comp->bullet.begin(); it != comp->bullet.end(); )
    {
        auto c = *it;

        if (c->team == owner->team)
        {
            ++it;
            continue;
        }

        auto z = c->getComponent<HitBox>();
        if (!z || !z->isactive || !overlaps(z))
        {
            ++it;
            continue;
        }

        int damage = z->damage;
        if (damage == 0)
        {
            ++it;
            continue;
        }

        it = comp->bullet.erase(it);

        if (actualtime >= Iframe)
        {
            damageTaken = damage;
            actualtime = 0;
            return true;
        }
    }
    return false;
}

bool HurtBox::intersect()
{
    for (auto b : other)
    {
        if (b == owner) continue;
        if (b->team == owner->team) continue;

        if (checkHitBox(b))  return true;
        if (checkBullets(b)) return true;
        
        auto spawner = b->getComponent<AiMobSpawner>();
        if (spawner)
        {
            for (auto mob : spawner->liste)
            {
                if (mob == owner) continue;
                if (mob->team == owner->team) continue;
                if (checkHitBox(mob)) return true;
            }
        }
    }
    return false;
}