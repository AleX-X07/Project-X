#include "ElementMain.h"
#include "ChemicalManager.h"

ElementMain::ElementMain(ChemicalManager& _Manager, float _duration) : Manager(_Manager) {
    duration = _duration;
}

ElementMain::~ElementMain() {
}

void ElementMain::update(float dt) {
    
}
