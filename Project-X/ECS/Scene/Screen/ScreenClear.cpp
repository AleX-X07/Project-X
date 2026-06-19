#include "ScreenClear.h"

ScreenClear::ScreenClear(Object* _owner, Scene* currentScene) : ScreenManager(_owner, currentScene){
}

void ScreenClear::update(float deltaTime) {
    auto click = owner->getComponent<MouseComponent>()->isClick();
    
    if (click) {
        auto& previous = getCurrentScene()->getPreviousScreen(); 
        getCurrentScene()->setState(Scene::State::Run);
        if (!previous.empty()) {
            getCurrentScene()->setObjectsScreen(getCurrentScene()->getPreviousScreen().back());
            getCurrentScene()->getPreviousScreen().pop_back();   
        }          
    }
}
