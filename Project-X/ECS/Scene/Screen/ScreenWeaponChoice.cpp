#include "ScreenWeaponChoice.h"

#include "../../../Main/GameEngine.h"

ScreenWeaponChoice::ScreenWeaponChoice(Object* _owner, Scene* scene, std::string _file) : ScreenManager(_owner, scene), file(_file){
}

void ScreenWeaponChoice::update(float deltaTime) {
    if (owner->getComponent<MouseComponent>()->isClick()) {
        setScreen(file);
    }
}
