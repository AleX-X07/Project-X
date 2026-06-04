#include "ExperienceContainer.h"

ExperienceContainer::ExperienceContainer(Object* _owner, int _exp) : Component(_owner)
{
    Exp = _exp;
}

int ExperienceContainer::getExp()
{
    return Exp;
}

