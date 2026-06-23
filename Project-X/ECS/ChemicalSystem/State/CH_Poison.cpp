#include "CH_Poison.h"
#include "../ChemicalManager.h"
#include "../../Graphics/RenderFile.h"
#include "../../Tool/HealthComponent.h"

CH_Poison::CH_Poison(ChemicalManager& _Manager, float _duration, float _damage, float _interval) : ElementMain(_Manager, _duration) {
    damage = _damage;
    interval = _interval;
    
    auto comp = Manager.getOwner()->getComponent<RenderFile>();
    if (comp) {
        comp->getRect()->setFillColor(sf::Color::Green);
    }
    
    file = "Assets/EffectIcon/PoisonIcon.png";
}

void CH_Poison::update(float dt) {
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
        
        isactive = false;
    }
}