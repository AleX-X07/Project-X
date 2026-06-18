#include "CH_Fire.h"
#include "../ChemicalManager.h"
#include "../../Graphics/RenderFile.h"
#include "../../Tool/HealthComponent.h"

CH_Fire::CH_Fire(ChemicalManager& _Manager, float _duration, float _damage, float _interval) : ElementMain(_Manager, _duration) {
    damage = _damage;
    interval = _interval;
    
    auto comp = Manager.getOwner()->getComponent<RenderFile>();
    if (comp) {
        comp->getRect()->setFillColor(sf::Color::Red);
    }
    
    file = "Assets/EffectIcon/FireIcon.png";
}

void CH_Fire::update(float dt) {
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
