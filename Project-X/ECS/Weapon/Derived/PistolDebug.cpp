#include ".h/PistolDebug.h"

PistolDebug::PistolDebug(Object* _owner) : WeaponMain(_owner)
{
    spread = 3;
    fireRate = 1;
    speed = 1000;
    Bulletquantity = 1;
}

Object* PistolDebug::CreateBullet(float angle)
{
    Object* ball = new Object(owner->getPosition(), {25,25});
    
    ball->addComponent(new BulletSystemComponent(ball, speed, angle, 10, 30));
    ball->addComponent(new RenderComponent(ball, "Assets/Debug/DebugBulletblue.png"));
    ball->addComponent(new HitBox(ball, {25, 25}));
    return ball;
}
