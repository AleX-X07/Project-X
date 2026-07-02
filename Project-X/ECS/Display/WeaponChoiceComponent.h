#pragma once
#include "../Component.h"
#include "../../Scene/Scene.h"
#include "../../Reader/WeaponReader.h"

class GameEngine;

class WeaponChoiceComponent : public Component {
private:
    std::vector<Object*> weapons;
    sf::RectangleShape* myChoices;
    
    Object* currentW;
    Object* buying;
    
    bool notMoney;
    float timer = 0;
    
public:
    WeaponChoiceComponent(Object* _owner, Scene* currentScene);
    virtual ~WeaponChoiceComponent() override;
    
    void buy(Object* _w);
    
    virtual void update(float deltaTime) override;
    virtual void render() override;
};
