#include "HUD.h"

#include "../../../Main/GameEngine.h"
#include "../../Tool/HealthComponent.h"

HUD::HUD(Object* _owner) : Component(_owner){
}

void HUD::update(float dt) {
    for (auto& comp : myHUD) {
        comp->update(dt);
    }
}

void HUD::render() {
    
    auto* comp = owner->getComponent<CameraComponent>();
    
    GameEngine::getWindow()->setView(GameEngine::getWindow()->getDefaultView());
    
    for (auto& h : myHUD) {
        h->render();
    }
    
    if (comp != nullptr) {
        GameEngine::getWindow()->setView(*comp->view);
    }
}

void HUD::addHUD(Component* hud) {
    myHUD.push_back(hud);
}
