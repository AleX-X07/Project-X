#include "HealthComponent.h"
#include "../../Main/GameEngine.h"

HealthComponent::HealthComponent(Object* _owner, int _MaxHp, std::vector<Object*>& _sceneObjects)  : Component(_owner), sceneObjects(_sceneObjects) {
    MaxHp = _MaxHp;
    hp = _MaxHp;
    
    buffer.loadFromFile("Assets/Sound/Hurt.wav");
    sound = new sf::Sound(buffer);
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
    
    if (owner->hasComponent<InputComponent>()) {
        sound->play();
    }
}

void HealthComponent::Death()
{
    alive = false;
}

int HealthComponent::getHp()
{
    return hp;
}
