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
#include "Capacity/CA_Tank.h"

CapacityManager::CapacityManager(Object* _owner, CapacityMain* _ActualCapa, CapacityMain* _SecondaryCapa, CapacityMain* _UltiCapa) : Component(_owner) {
    winSize = GameEngine::getWindow()->getSize();
    mapping = GamepadUtils::getMapping(0);

    ActualCapa = _ActualCapa;
    SecondaryCapa = _SecondaryCapa;
    UltiCapa = _UltiCapa;
    
    if (ActualCapa != nullptr) {
        ActualCapa->HUDrect.setPosition({(static_cast<float>(winSize.x) - 70*3), (static_cast<float>(winSize.y) - 100)});
        ActualCapa->HUDlevel.setPosition({(ActualCapa->HUDrect.getPosition().x), (ActualCapa->HUDrect.getPosition().y + 60)});
    }
    if (SecondaryCapa != nullptr) {
        SecondaryCapa->HUDrect.setPosition({(static_cast<float>(winSize.x) - 70*2), (static_cast<float>(winSize.y) - 100)});
        SecondaryCapa->HUDlevel.setPosition({(SecondaryCapa->HUDrect.getPosition().x), (SecondaryCapa->HUDrect.getPosition().y + 60)});
    }
    if (UltiCapa != nullptr) {
        UltiCapa->HUDrect.setPosition({(static_cast<float>(winSize.x) - 70), (static_cast<float>(winSize.y) - 100)});
        UltiCapa->HUDlevel.setPosition({(UltiCapa->HUDrect.getPosition().x), (UltiCapa->HUDrect.getPosition().y + 60)});
    }
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
    if (ActualCapa != nullptr) {
        ActualCapa->update(deltaTime);
        if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Capacity-1")) && ActualCapa->level >= 1) {
            ActualCapa->activate();
        }
    }
    if (SecondaryCapa != nullptr) {
        SecondaryCapa->update(deltaTime);
        if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Capacity-2")) && SecondaryCapa->level >= 1) {
            SecondaryCapa->activate();
        }
    }
    if (UltiCapa != nullptr) {
        UltiCapa->update(deltaTime);
        if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Capacity-3")) && UltiCapa->level >= 1) {
            UltiCapa->activate();
        }
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
        
        if (ActualCapa != nullptr) {
            if (ActualCapa->level != ActualCapa->maxLevel) {
                offerUpgrade(ActualCapa);
            }
        }
        if (SecondaryCapa != nullptr) {
            if (SecondaryCapa->level != SecondaryCapa->maxLevel) {
                offerUpgrade(SecondaryCapa);
            }
        }
        if (UltiCapa != nullptr) {
            if (UltiCapa->level != UltiCapa->maxLevel) {
                offerUpgrade(UltiCapa);
            }
        }
    }
}

void CapacityManager::render() {
    if (ActualCapa != nullptr) {
        ActualCapa->render();
    }
    if (SecondaryCapa != nullptr) {
        SecondaryCapa->render();
    }
    if (UltiCapa != nullptr) {
        UltiCapa->render();
    }
    
    for (auto& c : buttonList) {
        c.render();
    }
}

void CapacityManager::offerUpgrade(CapacityMain* capa) {
    buttonList.emplace_back(owner, capa);
}