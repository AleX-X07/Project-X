#pragma once

class GameEngine;
class Object;
class MouseComponent;

struct Transition {
    
    enum class TransitionType {
        Button,
    };
    
    TransitionType type;
    Object* owner;
    int targetID;
    
    Transition(int _targetID, TransitionType _type, Object* _owner);
    ~Transition() = default;
    
    void update();
};
