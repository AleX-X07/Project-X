#include "ScreenDeath.h"

ScreenDeath::ScreenDeath(Object* _owner, Scene* scene, std::string _file) : ScreenManager(_owner, scene), file(_file) {
}

void ScreenDeath::update(float deltaTime) {
    auto health = owner->getComponent<HealthComponent>()->getHp();
    if (health <= 0) {
        setScreen(file);
    }
}
