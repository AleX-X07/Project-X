#include "WeaponReader.h"

std::unordered_map<std::string, argsWeapon> WeaponReader::weapons = std::unordered_map<std::string, argsWeapon>();

std::unordered_map<std::string, argsWeapon>& WeaponReader::getWeapons() {
    return weapons;
}

void WeaponReader::read() {
    std::ifstream file("Data/Weapon/WeaponManager.json");
    if (file.is_open()) {
        nlohmann::json data = nlohmann::json::parse(file);
        
        for (auto& weapon : data["Weapon"]) {
            std::string myWeapon = weapon.get<std::string>() + ".json";
            std::string path = "Data/Weapon/Weapon/" + myWeapon;
            std::ifstream file2(path);
            if (file2.is_open()) {
                nlohmann::json data2 = nlohmann::json::parse(file2);
                
                argsWeapon newWeapon;
                newWeapon.WeaponName = data2["Name"];
                newWeapon.WeaponImage = data2["Image"];
                
                newWeapon.BulletImage = data2["BulletImage"];
                newWeapon.spread = data2["spread"];
                newWeapon.fireRate = data2["fireRate"];
                newWeapon.speed = data2["speed"];
                newWeapon.Bulletquantity = data2["Bulletquantity"];
                newWeapon.damage = data2["damage"];
                
                newWeapon.shakeIntensity = data2["shakeIntensity"];
                newWeapon.shakeDuration = data2["shakeDuration"];
                
                newWeapon.hasrecoil = data2["hasrecoil"];
                newWeapon.recoilTime = data2["recoilTime"];
                
                weapons[data2["Name"]] = newWeapon;
            }
        }   
    }
}