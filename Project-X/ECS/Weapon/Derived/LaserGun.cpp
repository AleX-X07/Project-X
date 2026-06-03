#include ".h/LaserGun.h"

LaserGun::LaserGun(Object* _owner) : WeaponMain(_owner)
{
    spread = 0;
    fireRate = 100;
    speed = 1000;
    Bulletquantity = 1;
    
    WeaponName = "Laser";
    
    auto comp = _owner->getComponent<BulletManager>();
    if (comp != nullptr)
    {
        comp->SetWeapon(this);
    }
}

Object* LaserGun::CreateBullet(float angle)
{
    Object* ball = new Object(owner->getPosition(), {25,25});
    
    ball->addComponent(new BulletSystemComponent(ball, speed, angle, 6, 1));
    ball->addComponent(new RenderComponent(ball, "Assets/Debug/DebugBulletblue.png"));
    ball->addComponent(new HitBox(ball, {25, 25}, true));
    return ball;
}
