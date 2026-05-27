#include "Transition.h"

#include "../ECS/MouseComponent.h"
#include "../Main/GameEngine.h"

Transition::Transition(int _targetID, TransitionType _type, Object* _owner) {
    targetID = _targetID;
    type = _type;
    owner = _owner;
}

void Transition::update() {
    if (type == TransitionType::Button) {
        auto mouse = owner->hasComponent<MouseComponent>();
        auto* isClick = owner->getComponent<MouseComponent>();
        if (mouse) {
            if (isClick->clicked()) {
                GameEngine::setScene(targetID);
            }
        }
    }
}
