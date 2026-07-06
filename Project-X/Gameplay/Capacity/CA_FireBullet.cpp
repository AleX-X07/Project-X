#include "CA_FireBullet.h"
#include "../../ECS/Tool/HealthComponent.h"
#include "../../ECS/Weapon/WeaponMain.h"

CA_FireBullet::CA_FireBullet(Object* _owner, float _Timer, float _Cooldown, int _Button) : CapacityMain(_owner, _Button) {
    Timer = _Timer;
    CoolDown = _Cooldown;
    
    HUDtx.loadFromFile("Assets/Capacity/FireBullet.png");
    HUDrect.setTexture(&HUDtx);
}

void CA_FireBullet::update(float dt) {
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
                comp->HasFire = false;
            }
        }
    }
}

void CA_FireBullet::activate() {
    if (CoolDownActualTime <= 0 && !IsActived) {
        IsActived = true;
        HUDrect.setFillColor(sf::Color({25, 25, 25, 255}));

        auto comp = owner->getComponent<WeaponMain>();
        if (comp) {
            comp->HasFire = true;
        }
    }
}

void CA_FireBullet::levelUp() {
    level += 1;
    if (level > maxLevel) {
        level = maxLevel;
    }
    else {
        HUDlevel.setTexture(nullptr);
        std::string test = "Assets/Debug/Level/CapaLV_" + std::to_string(level) + ".png";
        HUDtxLv.loadFromFile("Assets/Debug/Level/CapaLV_" + std::to_string(level) + ".png");
        HUDlevel.setTexture(&HUDtxLv);

        Timer += 1;
    }
}
