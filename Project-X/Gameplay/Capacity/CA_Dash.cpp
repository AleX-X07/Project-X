#include "CA_Dash.h"
#include "../../Main/GameEngine.h"

#include "../../ECS/Input/MouseComponent.h"

CA_Dash::CA_Dash(Object* _owner, float _speed, float _distance, float _Cooldown, int _Button) : CapacityMain(_owner, _Button) {
    speed = _speed;
    distance = _distance;
    CoolDown = _Cooldown;
    
    HUDtx.loadFromFile("Assets/Capacity/DoubleIcon.png");
    HUDrect.setTexture(&HUDtx);
}

void CA_Dash::update(float dt) {
    CoolDownActualTime -= dt;
    
    if (CoolDownActualTime <= 0) {
        HUDrect.setFillColor(sf::Color({255, 255, 255, 255}));
    }
    
    if (IsActived) {
        sf::Vector2f currentPos = owner->getPosition();
        sf::Vector2f direction = objectivePos - currentPos;
        float distanceLeft = std::sqrt(direction.x * direction.x + direction.y * direction.y);

        if (distanceLeft <= speed * dt) {
            owner->setPosition(objectivePos);
            IsActived = false;
            ActualTIme = 0;
        } else {
            direction /= distanceLeft;
            owner->setPosition(currentPos + direction * speed * dt);
            ActualTIme += dt;
        }
    }
}

void CA_Dash::activate() {
    if (CoolDownActualTime <= 0 && !IsActived) {
        IsActived = true;
        HUDrect.setFillColor(sf::Color({0, 0, 0, 255}));
        CoolDownActualTime = CoolDown;
        
        auto comp = owner->getComponent<MouseComponent>();
        if (comp) {
            sf::Vector2i mouseScreenPos = {
                (int)comp->getMousePosition().x,
                (int)comp->getMousePosition().y
            };
            sf::Vector2f mouseWorldPos = GameEngine::getWindow()->mapPixelToCoords(mouseScreenPos);

            Angle = std::atan2(
                mouseWorldPos.y - owner->getPosition().y,
                mouseWorldPos.x - owner->getPosition().x
            );
            
            objectivePos.x = owner->getPosition().x + distance * cos(Angle);
            objectivePos.y = owner->getPosition().y + distance * sin(Angle);
        }
    }
}

void CA_Dash::levelUp() {
    level += 1;
    if (level > maxLevel) {
        level = maxLevel;
    }
    else {
        HUDlevel.setTexture(nullptr);
        std::string test = "Assets/Debug/Level/CapaLV_" + std::to_string(level) + ".png";
        HUDtxLv.loadFromFile("Assets/Debug/Level/CapaLV_" + std::to_string(level) + ".png");
        HUDlevel.setTexture(&HUDtxLv);

        CoolDown -= 0.4;
    }
}