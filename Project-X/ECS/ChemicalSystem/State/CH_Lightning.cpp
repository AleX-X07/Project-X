#include "CH_Lightning.h"
#include "../ChemicalManager.h"
#include "../../Behaviour/AiDebugShoot.h"
#include "../../Behaviour/AiMoveTo.h"
#include "../../Graphics/RenderFile.h"
#include "../../Movement/MovementComponent.h"
#include "../../Tool/HealthComponent.h"

CH_Lightning::CH_Lightning(ChemicalManager& _Manager, float _duration, float _damage, float _interval) : ElementMain(_Manager, _duration) {
    damage = _damage;
    interval = _interval;
    
    auto comp = Manager.getOwner()->getComponent<RenderFile>();
    if (comp) {
        comp->getRect()->setFillColor(sf::Color::Yellow);
    }
    
    auto Ai = Manager.getOwner()->getComponent<AiMoveTo>();
    if (Ai) {
        storedSpeed = Ai->speed;
        Ai->speed = 0;
    }
    auto move = Manager.getOwner()->getComponent<MovementsComponent>();
    if (move) {
        storedSpeed = move->getSpeed();
        move->setSpeed(0);
    }
    
    auto AiShot = Manager.getOwner()->getComponent<AiDebugShoot>();
    if (AiShot) {
        AiShot->fireRate *= 2;
    }
    auto Shot = Manager.getOwner()->getComponent<WeaponMain>();
    if (Shot) {
        Shot->myArgs.fireRate *= 2;
    }
    
    file = "Assets/EffectIcon/LightningIcon.png";
}

void CH_Lightning::update(float dt) {
    TimerActualTime += dt;
    if (TimerActualTime > interval) {
        TimerActualTime = 0;
        auto comp = Manager.getOwner()->getComponent<HealthComponent>();
        if (comp) {
            comp->TakeDamage(damage);
        }
    }
    
    actualtime += dt;
    if (actualtime > duration) {
        actualtime = 0;
        
        auto comp = Manager.getOwner()->getComponent<RenderFile>();
        if (comp) {
            comp->getRect()->setFillColor(sf::Color::White);
        }
        auto Ai = Manager.getOwner()->getComponent<AiMoveTo>();
        if (Ai) {
            Ai->speed = storedSpeed;
        }
        auto move = Manager.getOwner()->getComponent<MovementsComponent>();
        if (move) {
            move->setSpeed(storedSpeed);
        }
        auto AiShot = Manager.getOwner()->getComponent<AiDebugShoot>();
        if (AiShot) {
            AiShot->fireRate /= 2;
        }
        auto Shot = Manager.getOwner()->getComponent<WeaponMain>();
        if (Shot) {
            Shot->myArgs.fireRate /= 2;
        }
        
        isactive = false;
    }
}