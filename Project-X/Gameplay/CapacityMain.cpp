#include "CapacityMain.h"
#include "../Main/GameEngine.h"

CapacityMain::CapacityMain(Object* _owner) : Component(_owner) {
    HUDrect.setSize({50, 50});
    HUDrect.setPosition({(1920 - 30), (1080 - 30)});
    
    HUDtx.loadFromFile("Assets/Debug/Debug_pink.png");
    HUDrect.setTexture(&HUDtx);
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
    
    auto cam = owner->getComponent<CameraComponent>();
    if (cam != nullptr)
    {
        GameEngine::getWindow()->setView(*cam->view);
    }
}

void CapacityMain::levelUp(int statIndex) {
    auto options = getUpgradeOptions();
    if (statIndex >= 0 && statIndex < options.size() && level < maxLevel) {
        options[statIndex].apply();
        level++;
    }
}