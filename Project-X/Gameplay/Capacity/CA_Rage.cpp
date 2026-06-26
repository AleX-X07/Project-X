#include "CA_Rage.h"

#include "../../ECS/Tool/HealthComponent.h"
#include "../../ECS/Weapon/WeaponMain.h"

CA_Rage::CA_Rage(Object* _owner, float _Timer, float _Cooldown, int _Button) : CapacityMain(_owner, _Button) {
    Timer = _Timer;
    CoolDown = _Cooldown;
    
    HUDtx.loadFromFile("Assets/Capacity/AlcoolIcon.png");
    HUDrect.setTexture(&HUDtx);
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
                if (RageSpread != 0)
                    comp->myArgs.spread /= RageSpread;
                comp->myArgs.damage /= RageDamage;
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
            comp->myArgs.spread *= RageSpread;
            comp->myArgs.damage *= RageDamage;
        }
    }
}

void CA_Rage::levelUp() {
    level += 1;
    if (level > maxLevel) {
        level = maxLevel;
    }
    else {
        HUDlevel.setTexture(nullptr);
        std::string test = "Assets/Debug/Level/CapaLV_" + std::to_string(level) + ".png";
        HUDtxLv.loadFromFile("Assets/Debug/Level/CapaLV_" + std::to_string(level) + ".png");
        HUDlevel.setTexture(&HUDtxLv);
    
        RageDamage += 0.5;
        RageSpread  -= 0.5;
        if (RageSpread < 0.1f) RageSpread = 0.1f; 
        CoolDown -= 0.5;
    }
}
