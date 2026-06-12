#pragma once
#include <SFML/Graphics.hpp>
#include "../ECS/Object.h"

#include <functional>
#include <vector>
#include <string>

struct UpgradeStat {
    std::string label;
    std::function<void()> apply;
    std::function<std::string()> preview;
};

class GameEngine;

class CapacityMain : public Component {
public:
    int level = 1;
    int maxLevel = 5;

    virtual std::vector<UpgradeStat> getUpgradeOptions() = 0;
    
public:
    sf::RectangleShape HUDrect;
    sf::Texture HUDtx;
    
    bool CanUse;
    float CoolDown;
    float CoolDownActualTime = 0;
public:
    CapacityMain(Object* _owner);
    ~CapacityMain();
    
    virtual void update(float dt);
    virtual void render();
    virtual void activate();
    
    void levelUp(int statIndex);
    void renderHUD();
};
