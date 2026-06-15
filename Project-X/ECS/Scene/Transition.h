#pragma once
#include "../Component.h"
#include <iostream>

class GameEngine;
class Object;
class MouseComponent;

enum TransitionType {
    Button,
};

class Transition : public Component{
private:
    TransitionType type;
    int targetID;
    
public:   
    Transition(Object* _owner, int _targetID, TransitionType _type);
    virtual ~Transition() override = default;
    
    virtual void update(float deltaTime) override;
};
