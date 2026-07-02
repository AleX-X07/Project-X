#pragma once
#include "../Object.h"
#include "../Component.h"

#include "../../ECS/Input/MouseComponent.h"
#include "../../ECS/Graphics/RenderFile.h"

class CapacityReader;
class GameEngine;

class SpellChoiceComponent : public Component {
private:
    std::vector<Object*> capacity;
    std::vector<sf::RectangleShape*> myChoices;

    Object* currentC = nullptr;
    Object* buying = nullptr;

    bool notMoney = false;
    float timer = 0;

public:
    SpellChoiceComponent(Object* owner);
    virtual ~SpellChoiceComponent() override;

    void buy(Object* _c);

    virtual void update(float deltaTime) override;
    virtual void render() override;
};