#pragma once
#include "../../Object.h"
#include "../../Graphics/RenderFile.h"

class GrenadeSystemComponent : public Component
{
private:
    int damage;
    
    float ExplosionTimer;
    
    float speed;
    float angle;
    
    sf::Vector2f ActualPosition;
    
    float resolution = 10;      // Number of point marking the trail of the bullet (more = lag / less = less acuaracy) (rec : 5-10)
    float timer = 0;
    float timerExp = 0;
    
    bool HasExploded = false;
    
    std::vector<Object*> Trail;

public:
    GrenadeSystemComponent(Object* _owner, float _speed, float _angle, int _damage, float _ExplosionTimer);
    ~GrenadeSystemComponent() override;

    float getSpeed();
    void setSpeed(float newSpeed);
    
    void update(float dt) override;
    void render() override;
    
    void CreateTrailPoint();
    void Explode();
    
    bool isExpired() const;
    
    int getDamage() const { return damage; }
};