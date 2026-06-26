#pragma once
#include "../Component.h"
#include "../../Scene/Scene.h"
#include "../../Reader/WeaponReader.h"

class GameEngine;

class WeaponChoiceComponent : public Component {
private:
    std::vector<Object*> weapons;
    sf::RectangleShape* myChoices;
    
public:
    WeaponChoiceComponent(Object* _owner, Scene* currentScene);
    virtual ~WeaponChoiceComponent() override;
    
    virtual void update(float deltaTime) override;
    virtual void render() override;
};
