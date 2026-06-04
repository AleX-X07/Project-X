#pragma once

#include "../../Object.h"

class GameEngine;

class ExperienceContainer : public Component
{
public:
    int Exp = 0;
    
public:
    ExperienceContainer(Object* _owner, int _exp);
    ~ExperienceContainer() override = default;

    int getExp();
};