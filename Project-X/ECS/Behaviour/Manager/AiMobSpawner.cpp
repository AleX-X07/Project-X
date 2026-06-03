#include "AiMobSpawner.h"
#include "../../../Main/GameEngine.h"

AiMobSpawner::AiMobSpawner(Object* _owner, sf::Vector2f _LevleSize, std::vector<Object*>& _sceneObjects)
    : Component(_owner), sceneObjects(_sceneObjects)
{
    LevelSize.x = _LevleSize.x - 50;
    LevelSize.y = _LevleSize.y - 50;
    timer = 1.5;
    srand(time(nullptr));
}

AiMobSpawner::~AiMobSpawner()
{
    for (auto c : liste)
    {
        delete c;
        c = nullptr;
    }
    liste.clear();
}

void AiMobSpawner::update(float dt)
{
    actualtime += dt;

    for (auto c : liste)
        c->update(dt);

    liste.erase(std::remove_if(liste.begin(), liste.end(), [](Object* c) {
        auto comp = c->getComponent<HealthComponent>();
        if (comp != nullptr && !comp->alive)
        {
            delete c;
            return true;
        }
        return false;
    }), liste.end());

    if (actualtime >= timer)
    {
        addMob();
        actualtime = 0;
    }
}

void AiMobSpawner::render()
{
    for (auto c : liste)
        c->render();
}

void AiMobSpawner::addMob()
{
    Object* target = nullptr;
    for (auto obj : sceneObjects)
    {
        if (obj->hasComponent<InputComponent>())
        {
            target = obj;
            break;
        }
    }
    if (target == nullptr) return;

    int r = rand() % 101;

    if (r <= 25)
    {
        Object* Mob = new Object({ static_cast<float>(rand()) / RAND_MAX * LevelSize.x, static_cast<float>(rand()) / RAND_MAX * LevelSize.y }, {50, 50});
        Mob->team = Object::Team::Enemy;
        Mob->addComponent(new HurtBox(Mob, {50, 50}, sceneObjects, 0));
        Mob->addComponent(new HitBox(Mob, {50, 50}, true));
        Mob->addComponent(new RenderComponent(Mob, "Assets/Debug/Trigger_DebugTX.png"));
        Mob->addComponent(new HealthComponent(Mob, 30));
        Mob->addComponent(new AiDebugShoot(Mob, *target, 10, 500, 10, 1, 1));
        Mob->addComponent(new AiMoveTo(Mob, sceneObjects, 50));
        liste.push_back(Mob);
    }
    else if (r <= 50)
    {
        Object* Mob = new Object({ static_cast<float>(rand()) / RAND_MAX * LevelSize.x, static_cast<float>(rand()) / RAND_MAX * LevelSize.y }, {50, 50});
        Mob->team = Object::Team::Enemy;
        Mob->addComponent(new HurtBox(Mob, {50, 50}, sceneObjects, 0));
        Mob->addComponent(new HitBox(Mob, {50, 50}, true));
        Mob->addComponent(new RenderComponent(Mob, "Assets/Debug/Trigger_DebugTX.png"));
        Mob->addComponent(new HealthComponent(Mob, 30));
        Mob->addComponent(new AiDebugShoot(Mob, *target, 10, 500, 360, 0.2, 15));
        liste.push_back(Mob);
    }
    else
    {
        Object* Mob = new Object({ static_cast<float>(rand()) / RAND_MAX * LevelSize.x, static_cast<float>(rand()) / RAND_MAX * LevelSize.y }, {50, 50});
        Mob->team = Object::Team::Enemy;
        Mob->addComponent(new HurtBox(Mob, {50, 50}, sceneObjects, 0));
        Mob->addComponent(new HitBox(Mob, {50, 50}, true));
        Mob->addComponent(new RenderComponent(Mob, "Assets/Debug/Collider_DebugTX.png"));
        Mob->addComponent(new HealthComponent(Mob, 30));
        Mob->addComponent(new AiMoveTo(Mob, sceneObjects, 200));
        liste.push_back(Mob);
    }
}