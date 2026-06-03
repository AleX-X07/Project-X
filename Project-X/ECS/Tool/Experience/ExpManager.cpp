#include "ExpManager.h"

ExpManager::ExpManager(Object* _owner) : Component(_owner)
{
    
}

void ExpManager::update(float deltaTime)
{
    
}

int ExpManager::getExp()
{
    return Exp;
}

void ExpManager::setExp(float _exp)
{
    Exp = _exp;
}


