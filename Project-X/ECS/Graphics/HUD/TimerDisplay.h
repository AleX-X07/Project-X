#pragma once
#include "../../Component.h"

class Object;
class TimerComponent;

class TimerDisplay : public Component {
private:
    Object* displayTimer;
    int timer;
    
public:
    TimerDisplay(Object* _owner, sf::Vector2f pos, int size, sf::Color color, std::string font);
    virtual ~TimerDisplay() override;
    
    void update(float dt) override;
    void render() override;
};
