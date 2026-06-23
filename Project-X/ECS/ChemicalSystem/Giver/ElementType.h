#pragma once

enum class ElementType { Fire, Poison, Ice, Light };

struct ElementData {
    ElementType type;
    float duration;
    float damage;
    float interval;
    float power;
};