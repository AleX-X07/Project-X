#pragma once
#include "Reader.h"
#include "../ECS/IncludeECS.h"
#include "../ECS/Object.h"
#include "../ECS/Weapon/WeaponMain.h"

class WeaponReader : public Reader {
private:
    static WeaponReader* myInstance;
    static std::unordered_map<std::string, argsWeapon> weapons;
    WeaponReader() = default;
    
public:

    virtual ~WeaponReader() override;
    
    static std::unordered_map<std::string, argsWeapon>& getWeapons();
    
    virtual void read() override;
    
    static WeaponReader* getInstance();
};