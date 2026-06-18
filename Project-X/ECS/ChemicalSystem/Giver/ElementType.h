#pragma once

enum class ElementType { Fire, Poison, Ice };

struct ElementData {
    ElementType type;
    float duration;
    float damage;
    float interval;
    float power;
};