#pragma once
#include "ScriptParser.h"
#include <string>
#include "SFML/Audio.hpp"
#include "../Object.h"

class GameEngine;

class CapacityMain : public Component {
public:
    sf::SoundBuffer buffer;
    sf::Sound sound{buffer};
    
public:
    CapacityMain(Object* _owner, const std::string& path);

    void Activate();
    void update(float dt) override;
    void render() override;

private:
    ScriptParser script;
    float        cooldownTimer = 0;

    void RunEvent(const std::string& eventName);
    void Execute(const Command& cmd);


    void SpawnProjectile(float size, float rad, float speed, float lifetime, int damage);
    void PlaySound(const std::string& file);
    void CheckCollisions();
    void DrawProjectiles(const std::string& color);
};