#include ".h/GrenadeLauncher.h"

GrenadeLauncher::GrenadeLauncher(Object* _owner) : WeaponMain(_owner)
{
    spread = 3;
    fireRate = 1;
    speed = 100;
    Bulletquantity = 1;
    
    WeaponName = "Deagle";
    
    auto comp = _owner->getComponent<BulletManager>();
    if (comp != nullptr)
    {
        comp->SetWeapon(this);
    }
}

Object* GrenadeLauncher::CreateBullet(float angle)
{
    Object* ball = new Object(owner->getPosition(), {25,25});
    
    ball->addComponent(new GrenadeSystemComponent(ball, speed, angle, 50, 3.5));
    ball->addComponent(new RenderComponent(ball, "Assets/Weapon/grenade.png"));
    ball->addComponent(new HitBox(ball, {0, 0}, false));
    return ball;
}
