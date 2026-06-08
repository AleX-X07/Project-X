#include "WeaponMain.h"
#include "../Bullet/BulletManager.h"
#include "../../Main/GameEngine.h"

WeaponMain::WeaponMain(Object* _owner, std::string file) : Component(_owner) {
    std::ifstream f(file);
    
    f >> spread;
    f >> fireRate;
    f >> speed;
    f >> Bulletquantity;
    f >> damage;
    
    f >> WeaponName;
    f >> WeaponImage;
    
    f >> shakeIntensity;
    f >> shakeDuration;
    
    f >> hasrecoil;
    
    
    auto comp = owner->getComponent<BulletManager>();
    if (comp != nullptr)
    {
        comp->SetWeapon(this);
    }
    
    WeaponRender = new Object({(owner->getPosition().x + 25), (owner->getPosition().y + 35)}, {50, 50});
    WeaponRender->addComponent(new RenderComponent(WeaponRender, WeaponImage));
    
    auto ori = WeaponRender->getComponent<RenderComponent>();
    ori->getRect()->setOrigin({25.f, 25.f});
}

Object* WeaponMain::CreateBullet(float angle) {
    // FeedBack
    auto Cam = owner->getComponent<CameraComponent>();
    if (Cam != nullptr) {
        Cam->CameraShake(shakeIntensity, shakeDuration);
    }
    if (hasrecoil) {
        recoil(angle);
    }
    
    //Bullet
    Object* ball = new Object(owner->getPosition(), {25,25});
    
    ball->addComponent(new BulletSystemComponent(ball, speed, angle, 7.5, 10));
    ball->addComponent(new RenderComponent(ball, "Assets/Debug/DebugBulletblue.png"));
    ball->addComponent(new HitBox(ball, {25, 25}, true, damage));
    
    return ball;
}

void WeaponMain::recoil(float angle) {
    float rad = angle * 3.14159265f / 180.f;
    sf::Vector2f recoilDir = { std::cos(rad), std::sin(rad) };
    
    sf::Vector2f pos = owner->getPosition();
    
    recoilStartPos = pos;
    recoilTargetPos = pos - recoilDir * 100.f;
    
    recoilTime = 0.f;
}

void WeaponMain::update(float deltaTime) {
    //Recoil
    if (recoilTime < 1.f)
    {
        recoilTime += deltaTime * 10.f;
        if (recoilTime > 1.f) recoilTime = 1.f;


        sf::Vector2f newPos = recoilStartPos + (recoilTargetPos - recoilStartPos) * recoilTime;

        owner->setPosition(newPos);
    }
    
    //WeaponRender
    WeaponRender->update(deltaTime);
    WeaponRender->setPosition({(owner->getPosition().x + 25), (owner->getPosition().y + 35)});
    
    //WeaponPositionning
    auto Mouseangle = owner->getComponent<MouseComponent>();
    auto comp = WeaponRender->getComponent<RenderComponent>();
    
    Xjoystick = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U);
    Yjoystick = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::V);

    if (sf::Joystick::isConnected(0) && (std::abs(Xjoystick) > 20 || std::abs(Yjoystick) > 20))
    {
        weaponAngle = std::atan2(Yjoystick, Xjoystick) * 180.0f / 3.14159f;;
    }
    else
    {
        MouseWorldPosition = GameEngine::getWindow()->mapPixelToCoords(Mouseangle->getMousePosition());

        weaponAngle = std::atan2(
            MouseWorldPosition.y - owner->getPosition().y,
            MouseWorldPosition.x - owner->getPosition().x
        ) * 180.0f / 3.14159f;
    }
    
    if (weaponAngle > 90.f || weaponAngle < -90.f) {
        comp->getRect()->setScale({-1.f, -1.f});
    }
    else {
        comp->getRect()->setScale({-1.f, 1.f});
    }
    
    comp->getRect()->setRotation(sf::Angle(sf::degrees(weaponAngle)));
}

void WeaponMain::render() {
    WeaponRender->render();
}

void WeaponMain::ChangeWeapon(std::string file) {
    std::ifstream f(file);
    
    f >> spread;
    f >> fireRate;
    f >> speed;
    f >> Bulletquantity;
    f >> damage;
    
    f >> WeaponName;
    f >> WeaponImage;
    
    f >> shakeIntensity;
    f >> shakeDuration;
    
    f >> hasrecoil;
    
    
    auto comp = owner->getComponent<BulletManager>();
    if (comp != nullptr)
    {
        comp->SetWeapon(this);
    }
    
    WeaponRender = new Object({(owner->getPosition().x + 25), (owner->getPosition().y + 35)}, {50, 50});
    WeaponRender->addComponent(new RenderComponent(WeaponRender, WeaponImage));
    
    auto ori = WeaponRender->getComponent<RenderComponent>();
    ori->getRect()->setOrigin({25.f, 25.f});
}
