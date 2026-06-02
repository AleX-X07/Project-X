#include "AiMobSpawner.h"
#include "../../../Main/GameEngine.h"

AiMobSpawner::AiMobSpawner(Object* _owner, Object& _target, sf::Vector2f _LevleSize, std::vector<Object*>& _sceneObjects) : Component(_owner), target(_target), sceneObjects(_sceneObjects)
{
    LevelSize = _LevleSize;
    timer = 2;
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
    {
        c->update(dt);
        auto comp = c->getComponent<HealthComponent>();
        if (comp != nullptr)
        {
            if (!comp->alive)
            {
                liste.erase(std::find(liste.begin(), liste.end(), c));
            }
        }
    }
    
    if (actualtime >= timer)
    {
        addMob();
        actualtime = 0;
    }
}

void AiMobSpawner::render()
{
    for (auto c : liste)
    {
        c->render();
    }
}

void AiMobSpawner::addMob()
{
    Object* Mob = new Object({ static_cast<float>(rand()) / RAND_MAX * LevelSize.x,static_cast<float>(rand()) / RAND_MAX * LevelSize.y }, {50, 50});
    
    Mob->addComponent(new HurtBox(Mob, {50, 50}, sceneObjects));
    Mob->addComponent(new RenderComponent(Mob, "Assets/Debug/Collider_DebugTX.png"));
    Mob->addComponent(new HealthComponent(Mob, 20));
    Mob->addComponent(new AiDebugShoot(Mob, target, 10, 500, 10, 1));
    
    liste.push_back(Mob);
}