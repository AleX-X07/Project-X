#include "CapacityMain.h"
#include "../Main/GameEngine.h"

CapacityMain::CapacityMain(Object* _owner, int Button) : Component(_owner) {
    HUDrect.setSize({50, 50});
    HUDrect.setPosition({(1920 - 30), (1080 - 100)});
    
    HUDlevel.setSize({50, 10});
    HUDlevel.setPosition({(HUDrect.getPosition().x), (HUDrect.getPosition().y + 60)});
    
    // HUDtxLv.loadFromFile("Assets/Debug/Level/CapaLV_" + std::to_string(level) + ".png");
    // HUDlevel.setTexture(&HUDtxLv);
    
    LinkButton = Button;
}

CapacityMain::~CapacityMain() {
    
}

void CapacityMain::update(float dt) {
    
}

void CapacityMain::render() {
    renderHUD();
}

void CapacityMain::activate() {
    
}

void CapacityMain::renderHUD() {
    GameEngine::getWindow()->setView(GameEngine::getWindow()->getDefaultView());
    GameEngine::getWindow()->draw(HUDrect);
    
    if (level > 0) {
        GameEngine::getWindow()->draw(HUDlevel);
    }
    
    auto cam = owner->getComponent<CameraComponent>();
    if (cam != nullptr) {
        GameEngine::getWindow()->setView(*cam->view);
    }
}

void CapacityMain::setTexture(std::string _tex) {
    HUDtxLv.loadFromFile(_tex);
    HUDlevel.setTexture(&HUDtxLv);
}

void CapacityMain::levelUp() {
    level += 1;
    if (level > maxLevel) {
        level = maxLevel;
    }
    
    // HUDlevel.setTexture(nullptr);
    // HUDtxLv.loadFromFile("Assets/Debug/Level/CapaLV_" + std::to_string(level) + ".png");
    // HUDlevel.setTexture(&HUDtxLv);
}
