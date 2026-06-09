#include "Transition.h"

#include "../Movement/MovementComponent.h"
#include "../../Main/GameEngine.h"

Transition::Transition(Object* _owner, int _targetID, TransitionType _type) : Component(_owner), targetID(_targetID), type(_type) {
}

void Transition::update(float deltaTime) {
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
