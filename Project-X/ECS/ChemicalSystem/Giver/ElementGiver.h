#pragma once
#include "../../Object.h"
#include "ElementType.h"

class ElementGiver : public Component {
public:
    std::vector<ElementData> elements;

    ElementGiver(Object* owner);

    void addElement(ElementType type, float duration, float damage, float interval);
    void applyTo(Object* target);
};