#include "ChemicalManager.h"

#include "../../Main/GameEngine.h"
#include "State/CH_Fire.h"

ChemicalManager::ChemicalManager(Object* owner) : Component(owner) {

}

ChemicalManager::~ChemicalManager() {
    for (auto z : List) {
        delete z;
        z = nullptr;
    }
}

void ChemicalManager::update(float deltaTime) {
    for (auto z : List) {
        z->update(deltaTime);
    }
    
    List.erase(
        std::remove_if(List.begin(), List.end(), [](ElementMain* b)
        {
            if (b->isactive == false)
            {
                delete b;
                return true;
            }
            return false;
        }),
        List.end()
    );
}

void ChemicalManager::addState(ElementMain* Element) {
    List.push_back(Element);
}

void ChemicalManager::render() {

}
