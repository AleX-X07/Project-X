#include "ElementGiver.h"
#include "../ChemicalManager.h"
#include "../State/CH_Fire.h"
#include "../State/CH_Ice.h"

ElementGiver::ElementGiver(Object* owner) : Component(owner) {}

void ElementGiver::addFire(ElementType type, float duration, float damage, float interval) {
    elements.push_back({type, duration, damage, interval, 0});
}

void ElementGiver::addIce(ElementType type, float duration, float power) {
    elements.push_back({type, duration, 0, 0, power});
}

void ElementGiver::applyTo(Object* target) {
    auto chem = target->getComponent<ChemicalManager>();
    if (!chem) return;
    for (auto& e : elements) {
        switch (e.type) {
        case ElementType::Fire:
            chem->addState(new CH_Fire(*chem, e.duration, e.damage, e.interval));
            break;
        case ElementType::Ice:
             chem->addState(new CH_Ice(*chem, e.duration, e.power));
             break;
        }
    }
}