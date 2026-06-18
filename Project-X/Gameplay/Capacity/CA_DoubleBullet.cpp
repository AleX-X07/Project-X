#include "CA_DoubleBullet.h"

#include "../../ECS/Weapon/WeaponMain.h"

CA_DoubleBullet::CA_DoubleBullet(Object* _owner, float _Timer, float _Cooldown) : CapacityMain(_owner) {
    Timer = _Timer;
    CoolDown = _Cooldown;
}

void CA_DoubleBullet::update(float dt) {
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
                comp->myArgs.Bulletquantity /= 2;
            }
        }
    }
}

void CA_DoubleBullet::activate() {
    if (CoolDownActualTime <= 0 && !IsActived) {
        IsActived = true;
        HUDrect.setFillColor(sf::Color({0, 0, 0, 255}));

        auto comp = owner->getComponent<WeaponMain>();
        if (comp) {
            comp->myArgs.Bulletquantity *= 2;
        }
    }
}

void CA_DoubleBullet::levelUp() {
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