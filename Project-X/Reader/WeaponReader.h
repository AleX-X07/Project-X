#pragma once
#include "Reader.h"
#include "../ECS/IncludeECS.h"
#include "../ECS/Object.h"
#include "../ECS/Weapon/WeaponMain.h"

class WeaponReader : public Reader {
private:
    static std::unordered_map<std::string, argsWeapon> weapons;
    
public:
    WeaponReader() = default;
    virtual ~WeaponReader() override = default;
    
    static std::unordered_map<std::string, argsWeapon>& getWeapons();
    
    virtual void read() override;
};