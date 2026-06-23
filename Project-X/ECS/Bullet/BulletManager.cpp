#include "BulletManager.h"
#include "../../Main/GameEngine.h"

BulletManager::BulletManager(Object* _owner)
    : BulletSource(_owner), weapon(nullptr)
{
    actualTime = 0;
    mapping = GamepadUtils::getMapping(0);

    buffer.loadFromFile("Assets/Sound/Shoot.wav");
    sound = new sf::Sound(buffer);
    bufferBoom.loadFromFile("Assets/Sound/Boom3.wav");
    soundBoom = new sf::Sound(bufferBoom);
}

void BulletManager::update(float dt)
{
    if (!weapon) return;

    actualTime += dt;

    auto Comp = owner->getComponent<MouseComponent>();
    if (Comp->keepClick() && actualTime >= 1.0f / weapon->myArgs.fireRate)
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
        soundBoom->play();
        CreateBullet(owner, angle, 5);
        actualTime = 0;
    }

    for (auto& b : bullet)
        b->update(dt);

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
    bullet.erase(
        std::remove_if(bullet.begin(), bullet.end(), [](Object* b)
        {
            auto* mov = b->getComponent<GrenadeSystemComponent>();
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
    if (!weapon) return;

    for (int u = 0; u < weapon->myArgs.Bulletquantity; u++)
    {
        Xjoystick = sf::Joystick::getAxisPosition(0, mapping.rightStickX);
        Yjoystick = sf::Joystick::getAxisPosition(0, mapping.rightStickY);

        if (sf::Joystick::isConnected(0) && (std::abs(Xjoystick) > 20 || std::abs(Yjoystick) > 20))
        {
            float angleRad = std::atan2(Yjoystick, Xjoystick);
            float angleDeg = angleRad * 180.f / 3.14159265f;
            if (angleDeg < 0) angleDeg += 360.f;

            randomAngle = angleDeg + (rand() / (float)RAND_MAX) * (2 * weapon->myArgs.spread) - weapon->myArgs.spread;
        }
        else
        {
            randomAngle = _angle + (rand() / (float)RAND_MAX) * (2 * weapon->myArgs.spread) - weapon->myArgs.spread;
        }

        bullet.push_back(weapon->CreateBullet(randomAngle));
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
    delete soundBoom;
    sound = nullptr;
    soundBoom = nullptr;
}

void BulletManager::SetWeapon(WeaponMain* _weapon)
{
    weapon = _weapon;
}
