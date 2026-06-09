#include "HealthDisplay.h"

#include "RenderText.h"
#include "../Object.h"
#include "../../Main/GameEngine.h"
#include "../Tool/HealthComponent.h"

HealthDisplay::HealthDisplay(Object* owner) : Component(owner), HP(0) {
}

void HealthDisplay::update(float dt) {
    if (owner->hasComponent<HealthComponent>()) {
        HP = owner->getComponent<HealthComponent>()->getHp();
    }
}

void HealthDisplay::render() {
    GameEngine::getWindow()->setView(GameEngine::getWindow()->getDefaultView());
    GameEngine::getWindow()->draw(HP);
}


