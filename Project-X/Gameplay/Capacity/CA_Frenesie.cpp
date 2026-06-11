#include "CA_Frenesie.h"

#include "../../ECS/Tool/HealthComponent.h"
#include "../../ECS/Weapon/WeaponMain.h"

CA_Frenesie::CA_Frenesie(Object* _owner, float _Timer, float _Cooldown) : CapacityMain(_owner) {
    Timer = _Timer;
    CoolDown = _Cooldown;
}

void CA_Frenesie::update(float dt) {
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
                comp->myArgs.fireRate /= 2;
            }
        }
    }
}

void CA_Frenesie::activate() {
    if (CoolDownActualTime <= 0 && !IsActived) {
        IsActived = true;
        HUDrect.setFillColor(sf::Color({0, 0, 0, 255}));

        auto comp = owner->getComponent<WeaponMain>();
        if (comp) {
            comp->myArgs.fireRate *= 2;
        }
    }
}
