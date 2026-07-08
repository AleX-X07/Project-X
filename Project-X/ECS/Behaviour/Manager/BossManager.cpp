#include "BossManager.h"

#include "../../Box/HurtBox.h"
#include "../../ChemicalSystem/ChemicalManager.h"
#include "../../Tool/HealthBar.h"
#include "../../Tool/Gold/GoldContainer.h"
#include "../Boss/AiBossCircle.h"
#include "../Boss/AiBossExplode.h"
#include "../Boss/AiBossShot.h"

BossManager::BossManager(Object* _owner, float _Timer, std::vector<Object*>& _sceneObjects, bool _level) : Component(_owner), sceneObjects(_sceneObjects){
    Timer = _Timer;
    std::srand(std::time(nullptr));
    level = _level;
}

BossManager::~BossManager() {

}

void BossManager::update(float deltaTime) {
    ActualTimer += deltaTime;
    actualtime += deltaTime;
    
    if (ActualTimer > Timer && !hasspawn) {
        spawnBoss();
        hasspawn = true;
    }
    
    if (hasspawn && (actualtime > rate)) {
        actualtime = 0;
        
        auto comp = owner->getComponent<AiMobSpawner>();
        for (auto y : comp->liste) {
            if (y->hasComponent<AiBossExplode>()) {
                int z = std::rand() % 3;
                if (z == 0) {
                    auto comp = y->getComponent<AiBossExplode>();
                    comp->CreateBullet(owner, 5);
                }
                if (z == 1) {
                    auto comp = y->getComponent<AiBossCircle>();
                    comp->active = true;
                }
                if (z == 2) {
                    auto comp = y->getComponent<AiBossShot>();
                    comp->CreateBullet(owner, 5);
                }
            }
        }
    }
}

void BossManager::render() {

}

void BossManager::spawnBoss() {
    
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
    
    if (!level) {
        Object* Boss = new Object({1920, 1080}, {120, 120});
        Boss->team = Object::Team::Enemy;
        Boss->addComponent(new HurtBox(Boss, {120, 120}, sceneObjects, 0));
        Boss->addComponent(new HitBox(Boss, {50, 50}, true, 10));
        Boss->addComponent(new HealthComponent(Boss, 200, sceneObjects));
        Boss->addComponent(new AiBossExplode(Boss, 20, 350, 12, false));
        Boss->addComponent(new AiBossCircle(Boss, 10, 200, 0, 10, false));
        Boss->addComponent(new AiBossShot(Boss, *target, 20, 400, 0, 0, 1, false));
        Boss->addComponent(new RenderFile(Boss, "Assets/Character/boss1.png"));
        Boss->addComponent(new AiMoveTo(Boss, sceneObjects, 50));
        Boss->addComponent(new ExperienceContainer(Boss, 50));
        Boss->addComponent(new HealthBar(Boss, sf::Color::Red));
        Boss->addComponent(new ChemicalManager(Boss));
        Boss->addComponent(new GoldContainer(Boss, 50, 100));
    
        auto comp = owner->getComponent<AiMobSpawner>();
        comp->liste.push_back(Boss);
    }
    else {
        Object* Boss = new Object({1920, 1080}, {120, 120});
        Boss->team = Object::Team::Enemy;
        Boss->addComponent(new HurtBox(Boss, {120, 120}, sceneObjects, 0));
        Boss->addComponent(new HitBox(Boss, {50, 50}, true, 20));
        Boss->addComponent(new HealthComponent(Boss, 400, sceneObjects));
        Boss->addComponent(new AiBossExplode(Boss, 40, 350, 20, true));
        Boss->addComponent(new AiBossCircle(Boss, 20, 200, 0, 10, true));
        Boss->addComponent(new AiBossShot(Boss, *target, 30, 400, 15, 0, 1, true));
        Boss->addComponent(new RenderFile(Boss, "Assets/Character/boss1.png"));
        Boss->addComponent(new AiMoveTo(Boss, sceneObjects, 50));
        Boss->addComponent(new ExperienceContainer(Boss, 100));
        Boss->addComponent(new HealthBar(Boss, sf::Color::Red));
        Boss->addComponent(new ChemicalManager(Boss));
        Boss->addComponent(new GoldContainer(Boss, 100, 100));
    
        auto comp = owner->getComponent<AiMobSpawner>();
        comp->liste.push_back(Boss);
    }
}