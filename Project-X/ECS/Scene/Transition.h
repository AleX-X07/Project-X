#pragma once
#include "../Component.h"

class GameEngine;
class Object;
class MouseComponent;

class Transition : public Component{
private:
    enum class TransitionType {
        Button,
    };
    
    TransitionType type;
    int targetID;
    
public:   
    Transition(Object* _owner, int _targetID, TransitionType _type);
    virtual ~Transition() override = default;
    
    virtual void update(float deltaTime) override;
};
