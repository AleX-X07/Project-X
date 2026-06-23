#include "CA_BigBullet.h"

#include "../../ECS/Tool/HealthComponent.h"
#include "../../ECS/Weapon/WeaponMain.h"

CA_bigbullet::CA_bigbullet(Object* _owner, float _Multi, float _Cooldown) : CapacityMain(_owner) {
    Multi = _Multi;
    CoolDown = _Cooldown;
    
    HUDtx.loadFromFile("Assets/Capacity/NukeIcon.png");
    HUDrect.setTexture(&HUDtx);
    
    HUDrect.setFillColor(sf::Color({0, 0, 0, 255}));
}

void CA_bigbullet::update(float dt) {
    CoolDownActualTime -= dt;
    
    if (CoolDownActualTime <= 0 && !IsActived) {
        HUDrect.setFillColor(sf::Color({255, 255, 255, 255}));
    }
    
    if (IsActived && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        
        if (stored) {
        IsActived = false;
        auto comp = owner->getComponent<WeaponMain>();
        if (comp) {
            comp->myArgs.lifeTime /= Multi;
            comp->myArgs.bulletSize.x /= Multi;
            comp->myArgs.bulletSize.y /= Multi;
            comp->myArgs.damage /= Multi;
            comp->myArgs.speed *= Multi;
            }
        }
        else {
            stored = true;
        }
    }
}

void CA_bigbullet::activate() {
    if (CoolDownActualTime <= 0 && !IsActived) {
        IsActived = true;
        HUDrect.setFillColor(sf::Color({0, 0, 0, 255}));
        stored = false;

        auto comp = owner->getComponent<WeaponMain>();
        if (comp) {
            comp->myArgs.lifeTime *= Multi;
            comp->myArgs.bulletSize.x *= Multi;
            comp->myArgs.bulletSize.y *= Multi;
            comp->myArgs.damage *= Multi;
            comp->myArgs.speed /= Multi;
        }
    }
}

void CA_bigbullet::levelUp() {
    level += 1;
    if (level > maxLevel) {
        level = maxLevel;
    }
    else {
        HUDlevel.setTexture(nullptr);
        std::string test = "Assets/Debug/Level/CapaLV_" + std::to_string(level) + ".png";
        HUDtxLv.loadFromFile("Assets/Debug/Level/CapaLV_" + std::to_string(level) + ".png");
        HUDlevel.setTexture(&HUDtxLv);

        Multi += 0.5;
    }
}