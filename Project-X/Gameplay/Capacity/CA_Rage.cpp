#include "CA_Rage.h"

#include "../../ECS/Tool/HealthComponent.h"
#include "../../ECS/Weapon/WeaponMain.h"

CA_Rage::CA_Rage(Object* _owner, float _Timer, float _Cooldown) : CapacityMain(_owner) {
    Timer = _Timer;
    CoolDown = _Cooldown;
}

void CA_Rage::update(float dt) {
    CoolDownActualTime -= dt;
    
    if (CoolDownActualTime <= 0 && !IsActived) {
        HUDrect.setFillColor(sf::Color({255, 255, 255, 255}));
    }
    
    if (IsActived) {
        TotalTime += dt;

        if (TotalTime > Timer) {
            IsActived = false;
            CoolDownActualTime = CoolDown;
            TotalTime = 0;

            auto comp = owner->getComponent<WeaponMain>();
            if (comp) {
                comp->myArgs.spread /= 2;
                comp->myArgs.damage /= 2;
            }
        }
    }
}

void CA_Rage::activate() {
    if (CoolDownActualTime <= 0 && !IsActived) {
        IsActived = true;
        HUDrect.setFillColor(sf::Color({0, 0, 0, 255}));

        auto comp = owner->getComponent<WeaponMain>();
        if (comp) {
            comp->myArgs.spread *= 2;
            comp->myArgs.damage *= 2;
        }
    }
}
