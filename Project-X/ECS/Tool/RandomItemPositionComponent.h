#pragma once
#include "../../Tool/Random.h"
#include "../Component.h"
#include "../../Tool/Globals.h"

class Object;

class RandomItemPositionComponent : public Component {
public:
    RandomItemPositionComponent(Object* _owner, sf::Vector2i _posX, sf::Vector2i _posY);
    virtual ~RandomItemPositionComponent() override = default;
};
