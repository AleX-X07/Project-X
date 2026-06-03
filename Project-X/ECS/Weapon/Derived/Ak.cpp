#include ".h/Ak.h"

Ak::Ak(Object* _owner) : WeaponMain(_owner)
{
    spread = 5;
    fireRate = 10;
    speed = 1000;
    Bulletquantity = 1;
    
    WeaponName = "Ak-47";
    
    auto comp = _owner->getComponent<BulletManager>();
    if (comp != nullptr)
    {
        comp->SetWeapon(this);
    }
}

Object* Ak::CreateBullet(float angle)
{
    Object* ball = new Object(owner->getPosition(), {25,25});
    
    ball->addComponent(new BulletSystemComponent(ball, speed, angle, 7.5, 5));
    ball->addComponent(new RenderComponent(ball, "Assets/Debug/DebugBulletblue.png"));
    ball->addComponent(new HitBox(ball, {25, 25}, true));
    return ball;
}
