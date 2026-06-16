#include "ScreenPaused.h"

ScreenPaused::ScreenPaused(Object* _owner, Scene* scene, std::string _file) : ScreenManager(_owner, scene), file(_file){
}

void ScreenPaused::update(float deltaTime) {
    if (sf::Keyboard::isKeyPressed(Input::getInput()->getKey("Pause"))) {
        setScreen(file);
    }
}
