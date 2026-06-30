#include "CA_Tank.h"

#include "../../ECS/Movement/MovementComponent.h"
#include "../../ECS/Tool/HealthComponent.h"
#include "../../ECS/Weapon/WeaponMain.h"
#include "../../Main/GameEngine.h"

CA_Tank::CA_Tank(Object* _owner, float _Timer, float _Cooldown, int _Button) : CapacityMain(_owner, _Button) {
    Timer = _Timer;
    CoolDown = _Cooldown;
    
    HUDtx.loadFromFile("Assets/Capacity/AlcoolIcon.png");
    HUDrect.setTexture(&HUDtx);
    
    speedModifier = 2;
    
    rect.setSize({owner->getSize().x + 20, owner->getSize().y + 20});
    TX.loadFromFile("Assets/Debug/Shield.png");
    rect.setTexture(&TX);
}

void CA_Tank::update(float dt) {
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
            
            auto comp = owner->getComponent<HealthComponent>();
            if (comp) {
                comp->invincible = false;
            }
            auto move = owner->getComponent<MovementsComponent>();
            if (move) {
                move->setSpeed(StoredSpeed);
            }
        }
    }
    
    rect.setPosition({owner->getPosition().x - 10, owner->getPosition().y - 10});
}

void CA_Tank::render() {
    CapacityMain::render();
    
    if (IsActived) {
        GameEngine::getWindow()->draw(rect);
    }
}

void CA_Tank::activate() {
    if (CoolDownActualTime <= 0 && !IsActived) {
        auto move = owner->getComponent<MovementsComponent>();
        if (move) {
            StoredSpeed = move->getSpeed();
            move->setSpeed(move->getSpeed() / speedModifier);
        }
        auto comp = owner->getComponent<HealthComponent>();
        if (comp) {
            comp->invincible = true;
        }
        
        IsActived = true;
        HUDrect.setFillColor(sf::Color({25, 25, 25, 255}));
    }
}

void CA_Tank::levelUp() {
    level += 1;
    if (level > maxLevel) {
        level = maxLevel;
    }
    else {
        HUDlevel.setTexture(nullptr);
        std::string test = "Assets/Debug/Level/CapaLV_" + std::to_string(level) + ".png";
        HUDtxLv.loadFromFile("Assets/Debug/Level/CapaLV_" + std::to_string(level) + ".png");
        HUDlevel.setTexture(&HUDtxLv);
        
        CoolDown -= 0.25;
        speedModifier -= 0.1;
    }
}