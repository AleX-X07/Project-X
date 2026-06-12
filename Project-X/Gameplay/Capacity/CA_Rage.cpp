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

std::vector<UpgradeStat> CA_Rage::getUpgradeOptions() {
    return {
            {
                "Durée",
                [this]() { Timer += 3.0f; },
                [this]() { return std::to_string((int)Timer) + "s → "
                                 + std::to_string((int)(Timer + 3)) + "s"; }
            },
            {
                "Cooldown",
                [this]() { CoolDown = std::max(1.0f, CoolDown - 2.0f); },
                [this]() { return std::to_string((int)CoolDown) + "s → "
                                 + std::to_string((int)std::max(1.f, CoolDown - 2)) + "s"; }
            }
    };
}