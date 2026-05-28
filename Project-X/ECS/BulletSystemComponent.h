#pragma once
#include "Object.h"
#include "renderComponent.h"

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
    BulletSystemComponent(Object* _owner, float _speed, float _angle, float _lifetime, int _damage);
    ~BulletSystemComponent() override;

    float getSpeed();
    void setSpeed(float newSpeed);
    
    void update(float dt) override;
    void render() override;
    
    void CreateTrailPoint();
    
    bool isExpired() const;
};