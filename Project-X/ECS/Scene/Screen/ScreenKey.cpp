#include "ScreenKey.h"

#include "../../../Tool/Input.h"

ScreenKey::ScreenKey(Object* _owner, Scene* scene, std::string _name, std::string _key) : ScreenManager(_owner,scene), name(_name), key(_key) {
}

void ScreenKey::update(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey(key))) {
        setScreen(name);
    }
}
