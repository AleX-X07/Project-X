#include "CA_Heal.h"

#include "../../ECS/Tool/HealthComponent.h"

CA_Heal::CA_Heal(Object* _owner, float _Amount, float _Interval, float _Timer, float _Cooldown, int _Button) : CapacityMain(_owner, _Button) {
    Amount = _Amount;
    Interval = _Interval;
    Timer = _Timer;
    CoolDown = _Cooldown;
    
    HUDtx.loadFromFile("Assets/Capacity/healIcon.png");
    HUDrect.setTexture(&HUDtx);
}

void CA_Heal::update(float dt) {
    CoolDownActualTime -= dt;
    
    if (CoolDownActualTime <= 0 && !IsActived) {
        HUDrect.setFillColor(sf::Color({255, 255, 255, 255}));
    }
    
    if (IsActived) {
        TotalTime += dt;
        ActualTIme += dt;
        if (ActualTIme >= Interval) {
            Heal();
            ActualTIme = 0;
        }
        if (TotalTime > Timer) {
            IsActived = false;
            CoolDownActualTime = CoolDown;
            TotalTime = 0;
        }
    }
}

void CA_Heal::activate() {
    if (CoolDownActualTime <= 0 && !IsActived) {
        IsActived = true;
        HUDrect.setFillColor(sf::Color({25, 25, 25, 255}));
    }
}

void CA_Heal::Heal() {
    auto comp = owner->getComponent<HealthComponent>();
    if (comp) {
        comp->hp += Amount;
        if (comp->hp > comp->MaxHp) {
            comp->hp = comp->MaxHp;
        }
    }
}

void CA_Heal::levelUp() {
    level += 1;
    if (level > maxLevel) {
        level = maxLevel;
    }
    else {
        HUDlevel.setTexture(nullptr);
        std::string test = "Assets/Debug/Level/CapaLV_" + std::to_string(level) + ".png";
        HUDtxLv.loadFromFile("Assets/Debug/Level/CapaLV_" + std::to_string(level) + ".png");
        HUDlevel.setTexture(&HUDtxLv);
    
        Amount += 10;
        CoolDown -= 0.5;
    }
}
