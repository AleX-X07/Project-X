#include "ScreenClick.h"

#include "../../Input/MouseComponent.h"

ScreenClick::ScreenClick(Object* _owner, Scene* scene, std::string _name) : ScreenManager(_owner, scene), name(_name) {
}

void ScreenClick::update(float deltaTime) {
    if (owner->getComponent<MouseComponent>()->isClick()) {
        setScreen(name);
    }
}
