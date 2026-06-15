#pragma once
#include <iostream>
#include "../Component.h"

class TimerComponent : public Component {
public:
    float timer;
    float actualTime = 0;
    
    bool hasEnd = false;
    
    sf::Font font;
    sf::Text* text;
    
public:
    TimerComponent(Object* _owner, float _timer);
    virtual ~TimerComponent() override;
    
    void update(float deltaTime) override;
    void render() override;
};
