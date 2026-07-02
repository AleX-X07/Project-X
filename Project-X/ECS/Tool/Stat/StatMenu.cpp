#include "StatMenu.h"
#include <fstream>

#include "StatManager.h"

StatMenu::StatMenu(Object* _owner, std::vector<Object*>& _objects) : Component(_owner), other(_objects) {
    Health = new StatUpgrade(owner->getComponent<StatManager>()->Health, 50, 1);
    Speed = new StatUpgrade(owner->getComponent<StatManager>()->speed, 50, 2);
    Damage = new StatUpgrade(owner->getComponent<StatManager>()->damage, 50, 3);
    ExpBoost = new StatUpgrade(owner->getComponent<StatManager>()->ExpBoost, 50, 4);
    GoldBoost = new StatUpgrade(owner->getComponent<StatManager>()->GoldBoost, 50, 5);
}

StatMenu::~StatMenu() {
    delete Health;
    delete Speed;
    delete Damage;
    delete ExpBoost;
    delete GoldBoost;
    
    Health = nullptr;
    Speed = nullptr;
    Damage = nullptr;
    ExpBoost = nullptr;
    GoldBoost = nullptr;
}

void StatMenu::update(float deltaTime) {
    Health->update(deltaTime);
    Speed->update(deltaTime);
    Damage->update(deltaTime);
    ExpBoost->update(deltaTime);
    GoldBoost->update(deltaTime);
    
    save();
}

void StatMenu::save() {
    std::ofstream file("Data/Stat/Stat.txt", std::ios::out);
    
    
    file << Health->Level << "\n";
    file << Speed->Level << "\n";
    file << Damage->Level << "\n";
    file << ExpBoost->Level << "\n";
    file << GoldBoost->Level << "\n";
    
    file.close();
}

void StatMenu::render() {
    Health->render();
    Speed->render();
    Damage->render();
    ExpBoost->render();
    GoldBoost->render();
}

