#include ".h/ShotGun.h"

shotgun::shotgun(Object* _owner) : WeaponMain(_owner)
{
    spread = 15;
    fireRate = 2;
    speed = 1000;
    Bulletquantity = 3;
    
    WeaponName = "ShorGun";
    
    auto comp = _owner->getComponent<BulletManager>();
    if (comp != nullptr)
    {
        comp->SetWeapon(this);
    }
}

Object* shotgun::CreateBullet(float angle)
{
    Object* ball = new Object(owner->getPosition(), {25,25});
    
    ball->addComponent(new BulletSystemComponent(ball, speed, angle, 7.5, 10));
    ball->addComponent(new RenderComponent(ball, "Assets/Debug/DebugBulletblue.png"));
    ball->addComponent(new HitBox(ball, {25, 25}, true));
    return ball;
}
