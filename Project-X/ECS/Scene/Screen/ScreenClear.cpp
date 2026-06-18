#include "ScreenClear.h"

ScreenClear::ScreenClear(Object* _owner, Scene* currentScene) : ScreenManager(_owner, currentScene){
}

void ScreenClear::update(float deltaTime) {
    auto click = owner->getComponent<MouseComponent>()->isClick();
    
    if (click) {
        auto& previous = getPreviousScreen(); 
        getCurrentScene()->setState(Scene::State::Run);
        getCurrentScene()->clearScreen();
        resetScreenSet();
        if (!previous.empty()) {
            getCurrentScene()->setObjectsScreen(getPreviousScreen().back());
            getPreviousScreen().pop_back();   
        }          
    }
}
