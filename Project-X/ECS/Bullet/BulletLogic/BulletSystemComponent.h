#pragma once
#include "../../Object.h"
#include "../../Graphics/RenderComponent.h"

class BulletSystemComponent : public Component
{
private:
    int damage;
    float lifetime;
    float speed;
    float angle;
    
    sf::Vector2f ActualPosition;
    
    float resolution = 10;
    float timer = 0;
    std::vector<Object*> Trail;

public:
    BulletSystemComponent(Object* _owner, float _speed, float _angle, float _lifetime);
    ~BulletSystemComponent() override;

    float getSpeed();
    void setSpeed(float newSpeed);
    
    void update(float dt) override;
    void render() override;
    
    void CreateTrailPoint();
    
    bool isExpired() const;
    
    int getDamage() const { return damage; }
};