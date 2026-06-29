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
    
public:
    SpellChoiceComponent(Object* owner);
    virtual ~SpellChoiceComponent() override;
    
    virtual void update(float deltaTime) override;
    virtual void render() override;
};
