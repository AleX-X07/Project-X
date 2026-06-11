#include "CapacityManager.h"

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
    
    ActualCapa->HUDrect.setPosition({(1920 - 70), (1080 - 70)});
    SecondaryCapa->HUDrect.setPosition({(1920 - 70*2), (1080 - 70)});
    UltiCapa->HUDrect.setPosition({(1920 - 70*3), (1080 - 70)});
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
}

void CapacityManager::render() {
    ActualCapa->render();
    SecondaryCapa->render();
    UltiCapa->render();
}
