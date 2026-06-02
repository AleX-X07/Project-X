#include "BulletManager.h"
#include "../../Main/GameEngine.h"

BulletManager::BulletManager(Object* _owner)
    : BulletSource(_owner)
{
    speed = 500;
    damage = 10;
    spread = 5;
    fireRate = 10;
    
    actualTime = 0;
    
    buffer.loadFromFile("Assets/Sound/Shoot.wav");
    sound =  new sf::Sound(buffer);
}

void BulletManager::update(float dt)
{
    actualTime += dt;
    
    auto Comp = owner->getComponent<MouseComponent>();
    if (Comp->clicked() && actualTime >= 1.0f / fireRate)
    {
        mouseScreenPos = {
            (int)Comp->getMousePosition().x,
            (int)Comp->getMousePosition().y
        };

        mouseWorldPos = GameEngine::getWindow()->mapPixelToCoords(mouseScreenPos);

        float angle = std::atan2(
            mouseWorldPos.y - owner->getPosition().y,
            mouseWorldPos.x - owner->getPosition().x
        ) * 180.0f / 3.14159f;
        
        sound->play();
        CreateBullet(owner, angle, 5);
        actualTime = 0;
    }
    
    for (auto& b : bullet)
    {
        b->update(dt);
    }
    
    bullet.erase(
    std::remove_if(bullet.begin(), bullet.end(), [](Object* b)
    {
        auto* mov = b->getComponent<BulletSystemComponent>();
        if (mov && mov->isExpired())
        {
            delete b;
            return true;
        }
        return false;
    }),
    bullet.end()
    );
}

void BulletManager::CreateBullet(Object* _owner, float _angle, float _lifetime)
{
    Xjoystick = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U);
    Yjoystick = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::V);
    
    if (sf::Joystick::isConnected(0) && (std::abs(Xjoystick) > 20 || std::abs(Yjoystick) > 20))
    {
        float angleRad = std::atan2(Yjoystick, Xjoystick);
        float angleDeg = angleRad * 180.f / 3.14159265f;
            
        if (angleDeg < 0) {
            angleDeg += 360.f;
        }
        
        Object* ball = new Object(owner->getPosition(), {25,25});
    
        randomAngle = angleDeg + (rand() / (float)RAND_MAX) * (2 * spread) - spread;
    
        ball->addComponent(new BulletSystemComponent(ball, speed, randomAngle, _lifetime, damage));
        ball->addComponent(new RenderComponent(ball, "Assets/Debug/DebugBulletblue.png"));
        ball->addComponent(new HitBox(ball, {25, 25}));
        bullet.push_back(ball);
    }
    else
    {
        Object* ball = new Object(owner->getPosition(), {25,25});
    
        randomAngle = _angle + (rand() / (float)RAND_MAX) * (2 * spread) - spread;
    
        ball->addComponent(new BulletSystemComponent(ball, speed, randomAngle, _lifetime, damage));
        ball->addComponent(new RenderComponent(ball, "Assets/Debug/DebugBulletblue.png"));
        ball->addComponent(new HitBox(ball, {25, 25}));
        bullet.push_back(ball);
    }
}

void BulletManager::render()
{
    for (auto& b : bullet)
    {
        b->render();
    }
}

BulletManager::~BulletManager()
{
    for (auto z : bullet)
    {
        delete z;
        z = nullptr;
    }
    bullet.clear();
    
    delete sound;
    sound = nullptr;
}