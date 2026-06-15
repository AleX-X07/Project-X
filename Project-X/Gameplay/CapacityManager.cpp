#include "CapacityManager.h"

#include "../ECS/Tool/Experience/ExpComponent.h"
#include "Capacity/CA_Heal.h"
#include "Capacity/CA_BulletExplode.h"
#include "Capacity/CA_Rage.h"
#include "Capacity/CA_Frenesie.h"
#include "Capacity/CA_BigBullet.h"
#include "Capacity/CA_DoubleBullet.h"
#include "Capacity/CA_Dash.h"

CapacityManager::CapacityManager(Object* _owner) : Component(_owner) {
    ActualCapa = new CA_Rage(owner, 10, 10);
    SecondaryCapa = new CA_DoubleBullet(owner, 10, 10);
    UltiCapa = new CA_Dash(owner, 4000, 200, 1);
    
    ActualCapa->HUDrect.setPosition({(1920 - 70*3), (1080 - 100)});
    ActualCapa->HUDlevel.setPosition({(ActualCapa->HUDrect.getPosition().x), (ActualCapa->HUDrect.getPosition().y + 60)});
    
    SecondaryCapa->HUDrect.setPosition({(1920 - 70*2), (1080 - 100)});
    SecondaryCapa->HUDlevel.setPosition({(SecondaryCapa->HUDrect.getPosition().x), (SecondaryCapa->HUDrect.getPosition().y + 60)});
    
    UltiCapa->HUDrect.setPosition({(1920 - 70), (1080 - 100)});
    UltiCapa->HUDlevel.setPosition({(UltiCapa->HUDrect.getPosition().x), (UltiCapa->HUDrect.getPosition().y + 60)});
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
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        ActualCapa->activate();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E)) {
        SecondaryCapa->activate();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
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
            comp->Exp = 0;
            
            pendnumber += 1;
            ExpNeed *= ExpMulti;
        }
    }
    
    if (pendnumber > 0 && !offered && !sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
        offered = true;
        pendnumber -=1;
        
        offerUpgrade(ActualCapa);
        offerUpgrade(SecondaryCapa);
        offerUpgrade(UltiCapa);
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