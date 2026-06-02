#include "WeaponMain.h"

WeaponMain::WeaponMain(Object* _owner) : Component(_owner)
{
    
}

Object* WeaponMain::CreateBullet(float angle)
{
    Object* ball = new Object(owner->getPosition(), {25,25});
    return ball;
}