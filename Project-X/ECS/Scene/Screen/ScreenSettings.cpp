#include "ScreenSettings.h"

#include "../../../Scene/Scene.h"


ScreenSettings::ScreenSettings(Object* _owner, Scene* currentScene, std::string _file) : ScreenManager(_owner, currentScene), file(_file){
}

void ScreenSettings::update(float deltaTime) {
    auto click = owner->getComponent<MouseComponent>()->isClick();
    if (click) {
        setScreen(file);
    }
}
