#include ".h/ShotGun.h"

shotgun::shotgun(Object* _owner) : WeaponMain(_owner)
{
    spread = 15;
    fireRate = 2;
    speed = 1000;
    Bulletquantity = 3;
}

Object* shotgun::CreateBullet(float angle)
{
    Object* ball = new Object(owner->getPosition(), {25,25});
    
    ball->addComponent(new BulletSystemComponent(ball, speed, angle, 10, 10));
    ball->addComponent(new RenderComponent(ball, "Assets/Debug/DebugBulletblue.png"));
    ball->addComponent(new HitBox(ball, {25, 25}));
    return ball;
}
