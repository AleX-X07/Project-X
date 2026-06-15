#include "TimerDisplay.h"

#include "../RenderText.h"
#include "../../Object.h"
#include "../../Tool/TimerComponent.h"

TimerDisplay::TimerDisplay(Object* _owner, sf::Vector2f pos, int size, sf::Color color, std::string font) : Component(_owner) {
    timer = 0;
    displayTimer = new Object({0,0},{0,0});
    displayTimer->addComponent(new RenderText(displayTimer, font));
    displayTimer->getComponent<RenderText>()->getText()->setPosition(pos);
    displayTimer->getComponent<RenderText>()->getText()->setCharacterSize(size);
    displayTimer->getComponent<RenderText>()->getText()->setFillColor(color);
}

TimerDisplay::~TimerDisplay() {
    delete displayTimer;
    displayTimer = nullptr;
}

void TimerDisplay::update(float dt) {
    if (owner->hasComponent<TimerComponent>()) {
        timer = owner->getComponent<TimerComponent>()->timer - owner->getComponent<TimerComponent>()->actualTime;
    }
    if (displayTimer->hasComponent<RenderText>()) {
        displayTimer->getComponent<RenderText>()->getText()->setString(std::to_string(timer));
    }
}

void TimerDisplay::render() {
    displayTimer->render();
}
