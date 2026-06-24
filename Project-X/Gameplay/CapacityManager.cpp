#include "CapacityManager.h"

#include "../ECS/Tool/Experience/ExpComponent.h"
#include "Capacity/CA_Heal.h"
#include "Capacity/CA_BulletExplode.h"
#include "Capacity/CA_Rage.h"
#include "Capacity/CA_Frenesie.h"
#include "Capacity/CA_BigBullet.h"
#include "Capacity/CA_DoubleBullet.h"
#include "Capacity/CA_Dash.h"
#include "Capacity/CA_FireBullet.h"
#include "Capacity/CA_PoisonBullet.h"
#include "../Main/GameEngine.h"

CapacityManager::CapacityManager(Object* _owner) : Component(_owner) {
    winSize = GameEngine::getWindow()->getSize();
    mapping = GamepadUtils::getMapping(0);
    
    ActualCapa = new CA_FireBullet(owner, 10, 10, 2);
    SecondaryCapa = new CA_PoisonBullet(owner, 10, 10, 1);
    UltiCapa = new CA_Dash(owner, 4000, 200, 3, 0);
    
    ActualCapa->HUDrect.setPosition({(static_cast<float>(winSize.x) - 70*3), (static_cast<float>(winSize.y) - 100)});
    ActualCapa->HUDlevel.setPosition({(ActualCapa->HUDrect.getPosition().x), (ActualCapa->HUDrect.getPosition().y + 60)});
    
    SecondaryCapa->HUDrect.setPosition({(static_cast<float>(winSize.x) - 70*2), (static_cast<float>(winSize.y) - 100)});
    SecondaryCapa->HUDlevel.setPosition({(SecondaryCapa->HUDrect.getPosition().x), (SecondaryCapa->HUDrect.getPosition().y + 60)});
    
    UltiCapa->HUDrect.setPosition({(static_cast<float>(winSize.x) - 70), (static_cast<float>(winSize.y) - 100)});
    UltiCapa->HUDlevel.setPosition({(UltiCapa->HUDrect.getPosition().x), (UltiCapa->HUDrect.getPosition().y + 60)});
    
    sf::Vector2f test = UltiCapa->HUDrect.getPosition();
}

CapacityManager::~CapacityManager() {
    delete ActualCapa;
    delete SecondaryCapa;
    delete UltiCapa;
    
    ActualCapa = nullptr;
    SecondaryCapa = nullptr;
    UltiCapa = nullptr;
}

void CapacityManager::update(float deltaTime) {
    ActualCapa->update(deltaTime);
    SecondaryCapa->update(deltaTime);
    UltiCapa->update(deltaTime);
    
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || mapping.RightBumper) && ActualCapa->level >= 1) {
        ActualCapa->activate();
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E) || mapping.LeftBumper) && SecondaryCapa->level >= 1) {
        SecondaryCapa->activate();
    }
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R) || GamepadUtils::getTriggerValue(0, mapping, true) > 15) && UltiCapa->level >= 1) {
        UltiCapa->activate();
    }
    
    for (auto& z : buttonList) {
        z.update(deltaTime);
    }
    
    if (pending) {
        buttonList.clear();
        pending = false;
    }
    
    auto comp = owner->getComponent<ExpManager>();
    if (comp) {
        if (comp->Exp >= ExpNeed) {
            comp->Exp -= ExpNeed;
            
            pendnumber += 1;
            ExpNeed *= ExpMulti;
            comp->level += 1;
        }
    }
    
    if (pendnumber > 0 && !offered && !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && !sf::Joystick::isButtonPressed(0, 0) && !sf::Joystick::isButtonPressed(0, 1) && !sf::Joystick::isButtonPressed(0, 2)) {
        offered = true;
        pendnumber -=1;
        
        if (ActualCapa->level != ActualCapa->maxLevel) {
            offerUpgrade(ActualCapa);
        }
        if (SecondaryCapa->level != SecondaryCapa->maxLevel) {
            offerUpgrade(SecondaryCapa);
        }
        if (UltiCapa->level != UltiCapa->maxLevel) {
            offerUpgrade(UltiCapa);
        }
    }
}

void CapacityManager::render() {
    ActualCapa->render();
    SecondaryCapa->render();
    UltiCapa->render();
    
    for (auto& c : buttonList) {
        c.render();
    }
}

void CapacityManager::offerUpgrade(CapacityMain* capa) {
    buttonList.emplace_back(owner, capa);
}