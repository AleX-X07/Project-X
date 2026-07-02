#include "StatManager.h"
#include <fstream>

#include "../HealthComponent.h"
#include "../../Movement/MovementComponent.h"
#include "../../Weapon/WeaponMain.h"
#include "../Experience/ExpManager.h"
#include "../Gold/GoldManager.h"

StatManager::StatManager(Object* _owner, std::vector<Object*>& _objects) : Component(_owner), other(_objects) {
    std::ifstream file("Data/Stat/Stat.txt");
    
    file >> Health;
    file >> speed;
    file >> damage;
    file >> ExpBoost;
    file >> GoldBoost;
    
    if (owner->hasComponent<HealthComponent>()) {
        owner->getComponent<HealthComponent>()->MaxHp *= Health * 0.15;
        owner->getComponent<HealthComponent>()->hp *= Health * 0.15;
    }
    if (owner->hasComponent<MovementsComponent>()) {
        owner->getComponent<MovementsComponent>()->setSpeed(owner->getComponent<MovementsComponent>()->getSpeed() * speed * 0.1);
    }
    if (owner->hasComponent<WeaponMain>()) {
        owner->getComponent<WeaponMain>()->myArgs.damage *= damage * 0.1;
    }
    if (owner->hasComponent<ExpManager>()) {
        owner->getComponent<ExpManager>()->multi *= ExpBoost * 0.1;
    }
    if (owner->hasComponent<GoldManager>()) {
        owner->getComponent<GoldManager>()->multi *= GoldBoost * 0.1;
    }
}

StatManager::~StatManager() {
    
}

