#include ".h/ShotGun.h"

#include "../../Tool/CameraComponent.h"

shotgun::shotgun(Object* _owner) : WeaponMain(_owner)
{
    spread = 15;
    fireRate = 2;
    speed = 1000;
    Bulletquantity = 3;
    
    WeaponName = "ShorGun";
    
    shakeDuration = 1;
    shakeIntensity = 1;
    
    auto comp = _owner->getComponent<BulletManager>();
    if (comp != nullptr)
    {
        comp->SetWeapon(this);
    }
}

Object* shotgun::CreateBullet(float angle) {
    auto Cam = owner->getComponent<CameraComponent>();
    Cam->CameraShake(shakeIntensity, shakeDuration);
    
    Object* ball = new Object(owner->getPosition(), {25,25});
    
    ball->addComponent(new BulletSystemComponent(ball, speed, angle, 7.5, 10));
    ball->addComponent(new RenderComponent(ball, "Assets/Debug/DebugBulletblue.png"));
    ball->addComponent(new HitBox(ball, {25, 25}, true));
    
    float rad = angle * 3.14159265f / 180.f;
    sf::Vector2f recoilDir = { std::cos(rad), std::sin(rad) };
    
    sf::Vector2f pos = owner->getPosition();
    
    recoilStartPos = pos;
    recoilTargetPos = pos - recoilDir * 100.f;
    
    recoilTime = 0.f;
    
    return ball;
}

void shotgun::update(float deltaTime) {
    if (recoilTime < 1.f)
    {
        recoilTime += deltaTime * 10.f;
        if (recoilTime > 1.f) recoilTime = 1.f;


        sf::Vector2f newPos = recoilStartPos + (recoilTargetPos - recoilStartPos) * recoilTime;

        owner->setPosition(newPos);
    }
}
