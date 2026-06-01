#pragma once
#include "../Object.h"

class BulletSource : public Component
{
public:
    std::vector<Object*> bullet;
    int damage = 0;

    BulletSource(Object* _owner);
    virtual ~BulletSource() = default;
};