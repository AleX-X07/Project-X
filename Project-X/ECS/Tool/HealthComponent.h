#pragma once
#include "../Object.h"
#include "SFML/Audio.hpp"

class GameEngine;

class HealthComponent final : public Component
{
public:
    int hp;
    int MaxHp;
    
    bool alive = true;
    
    std::vector<Object*>& sceneObjects;

    sf::SoundBuffer buffer;
    sf::Sound* sound;
    
public:
    HealthComponent(Object* _owner, int _MaxHp, std::vector<Object*>& _sceneObjects);
    virtual ~HealthComponent() override = default;
    void TakeDamage(int damage);
    
    int getHp();
    
    void Death();
};