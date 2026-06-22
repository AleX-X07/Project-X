#include "GoldContainer.h"
GoldContainer::GoldContainer(Object* _owner, int _gold, float luck) : Component(_owner) {
    srand(time(nullptr));
    
    int r = rand() % 101;
    if (r <= luck) {
        gold = _gold;
    }
    else {
        gold = 0;
    }
}

int GoldContainer::getGold() {
    return gold;
}

