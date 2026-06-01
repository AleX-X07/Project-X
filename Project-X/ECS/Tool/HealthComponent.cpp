#include "HealthComponent.h"
#include "../../Main/GameEngine.h"

HealthComponent::HealthComponent(Object* _owner, int _MaxHp)  : Component(_owner) {
    MaxHp = _MaxHp;
    hp = _MaxHp;
}

HealthComponent::~HealthComponent()
{

}

void HealthComponent::TakeDamage(int damage)
{
    hp -= damage;
    if (hp <= 0)
    {
        Death();
    }
    std::cout << owner << " : " << hp << std::endl;
}

void HealthComponent::Death()
{
    alive = false;
}

int HealthComponent::getHp()
{
    return hp;
}
