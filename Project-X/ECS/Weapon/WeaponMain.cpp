#include "WeaponMain.h"
#include "../Bullet/BulletManager.h"
#include "../../Main/GameEngine.h"
#include "../../Reader/WeaponReader.h"
#include "../ChemicalSystem/Giver/ElementGiver.h"
#include "../Graphics/RenderAngle.h"

WeaponMain::WeaponMain(Object* _owner, std::string weapon) : Component(_owner) {
    myArgs = WeaponReader::getWeapons()[weapon];
    
    auto comp = owner->getComponent<BulletManager>();
    if (comp != nullptr)
    {
        comp->SetWeapon(this);
    }
    
    WeaponRender = new Object({0,0}, myArgs.size);
    WeaponRender->addComponent(new RenderFile(WeaponRender, myArgs.WeaponImage));
    
    auto ori = WeaponRender->getComponent<RenderFile>();
    ori->getRect()->setOrigin({myArgs.size.x / 2.f, myArgs.size.y / 2.f});
}

Object* WeaponMain::CreateBullet(float angle) {
    // FeedBack
    auto Cam = owner->getComponent<CameraComponent>();
    if (Cam != nullptr) {
        Cam->CameraShake(myArgs.shakeIntensity, myArgs.shakeDuration);
    }
    if (myArgs.hasrecoil) {
        recoil(angle);
    }
    
    //Bullet
    Object* ball = new Object(owner->getPosition(), myArgs.bulletSize);
    
    ball->addComponent(new BulletSystemComponent(ball, myArgs.speed, angle, myArgs.lifeTime));
    ball->addComponent(new RenderAngle(ball, myArgs.BulletImage, angle));
    ball->addComponent(new HitBox(ball, myArgs.bulletSize, true, myArgs.damage));
    ball->addComponent(new ElementGiver(ball));
    ball->getComponent<ElementGiver>()->addElement(ElementType::Fire, 10, 5, 1);
    
    return ball;
}

void WeaponMain::recoil(float angle) {
    float rad = angle * 3.14159265f / 180.f;
    sf::Vector2f recoilDir = { std::cos(rad), std::sin(rad) };
    
    sf::Vector2f pos = owner->getPosition();
    
    recoilStartPos = pos;
    recoilTargetPos = pos - recoilDir * 100.f;
    
    myArgs.recoilTime = 0.f;
}

void WeaponMain::update(float deltaTime) {
    //Recoil
    if (myArgs.recoilTime < 1.f)
    {
        myArgs.recoilTime += deltaTime * 10.f;
        if (myArgs.recoilTime > 1.f) myArgs.recoilTime = 1.f;


        sf::Vector2f newPos = recoilStartPos + (recoilTargetPos - recoilStartPos) * myArgs.recoilTime;
        if (!std::isnan(newPos.x) && !std::isnan(newPos.y)) {
            owner->setPosition(newPos);
            CollisionCeck();
        }
        
        owner->setPosition(newPos);
        CollisionCeck();
    }
    
    //WeaponRender
    WeaponRender->update(deltaTime);
    WeaponRender->setPosition({(owner->getPosition().x + myArgs.positionOnPlayer.x), (owner->getPosition().y + myArgs.positionOnPlayer.y)});
    
    //WeaponPositionning
    auto Mouseangle = owner->getComponent<MouseComponent>();
    auto comp = WeaponRender->getComponent<RenderFile>();
    
    Xjoystick = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U);
    Yjoystick = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::V);

    if (sf::Joystick::isConnected(0) && (std::abs(Xjoystick) > 20 || std::abs(Yjoystick) > 20))
    {
        weaponAngle = std::atan2(Yjoystick, Xjoystick) * 180.0f / 3.14159f;
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

void WeaponMain::ChangeWeapon(argsWeapon newWeapon) {
    myArgs = newWeapon;
    
    auto comp = owner->getComponent<BulletManager>();
    if (comp != nullptr)
    {
        comp->SetWeapon(this);
    }
    
    WeaponRender = new Object({(owner->getPosition().x + 25), (owner->getPosition().y + 35)}, {50, 50});
    WeaponRender->addComponent(new RenderFile(WeaponRender,myArgs.WeaponImage));
    
    auto ori = WeaponRender->getComponent<RenderFile>();
    ori->getRect()->setOrigin({25.f, 25.f});
}

void WeaponMain::CollisionCeck() {
    if (owner->getPosition().x < 0) {
        owner->setPosition({0, owner->getPosition().y});
    }
    if (owner->getPosition().x > levelSize.x) {
        owner->setPosition({(levelSize.x - owner->getSize().x), owner->getPosition().y});
    }
    if (owner->getPosition().y < 0) {
        owner->setPosition({owner->getPosition().x, 0});
    }
    if (owner->getPosition().y > levelSize.y) {
        owner->setPosition({owner->getPosition().x, (levelSize.y - owner->getSize().y)});
    }
}
