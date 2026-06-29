#include "ScreenSpellChoice.h"

#include "../../../Main/GameEngine.h"

ScreenSpellChoice::ScreenSpellChoice(Object* _owner, Scene* scene, std::string _file) : ScreenManager(_owner, scene), file(_file){
}

void ScreenSpellChoice::update(float deltaTime) {
    if (owner->getComponent<MouseComponent>()->isClick()) {
        setScreen(file);
    }
}
