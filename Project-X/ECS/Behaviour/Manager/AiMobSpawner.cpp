#include "AiMobSpawner.h"
#include "../../../Main/GameEngine.h"
#include "../../ChemicalSystem/ChemicalManager.h"
#include "../../ChemicalSystem/ChemicalRenderer.h"
#include "../../ChemicalSystem/State/CH_Fire.h"
#include "../../Tool/Gold/GoldComponent.h"
#include "../../Tool/Gold/GoldContainer.h"

AiMobSpawner::AiMobSpawner(Object* _owner, std::vector<Object*>& _sceneObjects) : Component(_owner), sceneObjects(_sceneObjects) {
    LevelSize.x = levelSize.x - 50;
    LevelSize.y = levelSize.y - 50;
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
    for (auto c : ExpList)
    {
        delete c;
        c = nullptr;
    }
    for (auto c : GoldList)
    {
        delete c;
        c = nullptr;
    }
    
    liste.clear();
    ExpList.clear();
    GoldList.clear();
}

void AiMobSpawner::update(float dt)
{
    actualtime += dt;

    for (auto c : liste) {
        c->update(dt);
        auto hp = c->getComponent<HealthComponent>();
        auto Contain = c->getComponent<ExperienceContainer>();
        auto GoldContain = c->getComponent<GoldContainer>();
        if (!hp->alive) {
            Object* Exp = new Object(c->getPosition(), {25, 25});
            Exp->addComponent(new ExpComponent(Exp, {25, 25}, sceneObjects, Contain->Exp));
            Exp->addComponent(new RenderFile(Exp, "Assets/Debug/ExpDebug.png"));
            
            ExpList.push_back(Exp);
            
            Object* Gold = new Object({c->getPosition().x + 25, c->getPosition().y + 25}, {25, 25});
            Gold->addComponent(new GoldComponent(Gold, {25, 25}, sceneObjects, GoldContain->gold));
            Gold->addComponent(new RenderFile(Gold, "Assets/Debug/Debug_green.png"));
            
            if (GoldContain->gold > 0) {
                GoldList.push_back(Gold);
            }
        }
    }
    for (auto b : ExpList) {
        b->update(dt);
    }
    for (auto b : GoldList) {
        b->update(dt);
    }


    liste.erase(std::remove_if(liste.begin(), liste.end(), [](Object* c) {
        auto comp = c->getComponent<HealthComponent>();
        if (comp != nullptr && !comp->alive && c !=nullptr)
        {
            return true;
        }
        return false;
    }), liste.end());
    
    ExpList.erase(std::remove_if(ExpList.begin(), ExpList.end(), [](Object* c) {
        auto comp = c->getComponent<ExpComponent>();
        if (comp != nullptr && !comp->isActive && c !=nullptr)
        {
            return true;
        }
        return false;
    }), ExpList.end());
    
    GoldList.erase(std::remove_if(GoldList.begin(), GoldList.end(), [](Object* c) {
        auto comp = c->getComponent<GoldComponent>();
        if (comp != nullptr && !comp->isActive && c !=nullptr)
        {
            return true;
        }
        return false;
    }), GoldList.end());

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
    for (auto b : ExpList)
        b->render();
    for (auto b : GoldList)
        b->render();
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
        Object* Mob = new Object({ static_cast<float>(rand()) / RAND_MAX * LevelSize.x, static_cast<float>(rand()) / RAND_MAX * LevelSize.y }, {75, 75});
        Mob->team = Object::Team::Enemy;
        Mob->addComponent(new HurtBox(Mob, {75, 75}, sceneObjects, 0));
        Mob->addComponent(new HitBox(Mob, {75, 75}, true, 10));
        Mob->addComponent(new RenderFile(Mob, "Assets/Character/ennemi_1.png"));
        Mob->addComponent(new HealthComponent(Mob, 30, sceneObjects));
        Mob->addComponent(new AiDebugShoot(Mob, *target, 10, 500, 10, 1, 1));
        Mob->addComponent(new AiMoveTo(Mob, sceneObjects, 50));
        Mob->addComponent(new ExperienceContainer(Mob, 8));
        Mob->addComponent(new GoldContainer(Mob, 10, 100));
        Mob->addComponent(new ChemicalManager(Mob));
        Mob->addComponent(new ChemicalRenderer(Mob));
        
        liste.push_back(Mob);
    }
    else if (r <= 50)
    {
        Object* Mob = new Object({ static_cast<float>(rand()) / RAND_MAX * LevelSize.x, static_cast<float>(rand()) / RAND_MAX * LevelSize.y }, {75, 75});
        Mob->team = Object::Team::Enemy;
        Mob->addComponent(new HurtBox(Mob, {75, 75}, sceneObjects, 0));
        Mob->addComponent(new HitBox(Mob, {75, 75}, true, 10));
        Mob->addComponent(new RenderFile(Mob, "Assets/Character/ennemi_3.png"));
        Mob->addComponent(new HealthComponent(Mob, 30, sceneObjects));
        Mob->addComponent(new AiDebugShoot(Mob, *target, 10, 500, 360, 0.2, 15));
        Mob->addComponent(new ExperienceContainer(Mob, 10));
        Mob->addComponent(new GoldContainer(Mob, 10, 100));
        Mob->addComponent(new ChemicalManager(Mob));
        Mob->addComponent(new ChemicalRenderer(Mob));
        
        liste.push_back(Mob);
    }
    else
    {
        Object* Mob = new Object({ static_cast<float>(rand()) / RAND_MAX * LevelSize.x, static_cast<float>(rand()) / RAND_MAX * LevelSize.y }, {75, 75});
        Mob->team = Object::Team::Enemy;
        Mob->addComponent(new HurtBox(Mob, {75, 75}, sceneObjects, 0));
        Mob->addComponent(new HitBox(Mob, {75, 75}, true, 10));
        Mob->addComponent(new RenderFile(Mob, "Assets/Character/ennemi_2.png"));
        Mob->addComponent(new HealthComponent(Mob, 30, sceneObjects));
        Mob->addComponent(new AiMoveTo(Mob, sceneObjects, 200));
        Mob->addComponent(new ExperienceContainer(Mob, 3));
        Mob->addComponent(new GoldContainer(Mob, 10, 100));
        Mob->addComponent(new ChemicalManager(Mob));
        Mob->addComponent(new ChemicalRenderer(Mob));
        
        liste.push_back(Mob);
    }
}

void AiMobSpawner::giveExp() {

}
