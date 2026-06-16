#include "ScreenWin.h"

ScreenWin::ScreenWin(Object* _owner, Scene* scene, std::string _file) : ScreenManager(_owner, scene), file(_file){
}

void ScreenWin::update(float deltaTime) {
    auto timer = owner->getComponent<TimerComponent>()->timer - owner->getComponent<TimerComponent>()->actualTime;
    if (timer <= 0) {
        setScreen(file);    
    }
}
