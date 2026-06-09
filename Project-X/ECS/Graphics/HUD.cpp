#include "HUD.h"

#include "../Tool/HealthComponent.h"

HUD::HUD(Object* _owner) : Component(_owner){
}

void HUD::update(float dt) {
    if (owner->hasComponent<HealthComponent>()) {
        
    }
}

void HUD::render() {
    
}
