#include "ScreenClear.h"

ScreenClear::ScreenClear(Object* _owner, Scene* currentScene) : ScreenManager(_owner, currentScene){
}

void ScreenClear::update(float deltaTime) {
    auto click = owner->getComponent<MouseComponent>()->isClick();
    
    if (click) {
        auto& previous = getCurrentScene()->getPreviousScreen(); 
        if (!previous.empty()) {
            auto* toRestore = previous.back();
            previous.pop_back();               
            getCurrentScene()->setObjectsScreen(toRestore);
        }
        else {
            getCurrentScene()->setState(Scene::State::Run);
            getCurrentScene()->clearScreen();
        }
    }
}
