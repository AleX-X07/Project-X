#include "ElementGiver.h"
#include "../ChemicalManager.h"
#include "../State/CH_Fire.h"

ElementGiver::ElementGiver(Object* owner) : Component(owner) {}

void ElementGiver::addElement(ElementType type, float duration, float damage, float interval) {
    elements.push_back({type, duration, damage, interval});
}

void ElementGiver::applyTo(Object* target) {
    auto chem = target->getComponent<ChemicalManager>();
    if (!chem) return;
    for (auto& e : elements) {
        switch (e.type) {
        case ElementType::Fire:
            chem->addState(new CH_Fire(*chem, e.duration, e.damage, e.interval));
            break;
            // case ElementType::Poison:
            //     chem->addState(new CH_Poison(*chem, e.duration, e.damage, e.interval));
            //     break;
        }
    }
}