#pragma once
#include "../../Object.h"
#include "ElementType.h"

class ElementGiver : public Component {
public:
    std::vector<ElementData> elements;

    ElementGiver(Object* owner);

    void addFire(ElementType type, float duration, float damage, float interval);
    void addIce(ElementType type, float duration, float power);
    
    void applyTo(Object* target);
};