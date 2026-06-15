#include "CA_BulletExplode.h"

#include "../../ECS/Bullet/BulletManager.h"

CA_BulletExplode::CA_BulletExplode(Object* _owner, float _Quantity, float _Cooldown) : CapacityMain(_owner) {
    Quantity = _Quantity;
    CoolDown = _Cooldown;
    
    speed = 400;
    damage = 15;
}

void CA_BulletExplode::update(float dt) {
    CoolDownActualTime -= dt;
    
    if (CoolDownActualTime <= 0) {
        HUDrect.setFillColor(sf::Color({255, 255, 255, 255}));
    }
}

void CA_BulletExplode::activate() {
    if (CoolDownActualTime <= 0) {
        Shot();
        HUDrect.setFillColor(sf::Color({0, 0, 0, 255}));
        CoolDownActualTime = CoolDown;
    }
}

void CA_BulletExplode::Shot() {
    auto comp = owner->getComponent<BulletManager>();
    if (comp) {
        Angle = 0;
        for (int i = 0;i < Quantity; i++) {
            
            Object* ball = new Object(owner->getPosition(), {25,25});
            
            ball->addComponent(new BulletSystemComponent(ball, speed, Angle, 5));
            ball->addComponent(new RenderFile(ball, "Assets/Debug/DebugBulletblue.png"));
            ball->addComponent(new HitBox(ball, {25, 25}, true, damage));
            
            comp->bullet.push_back(ball);
            
            Angle += (360 / Quantity);
        }
    }
}
