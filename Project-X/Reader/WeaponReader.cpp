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
                newWeapon.size =  {data2["Size"][0], data2["Size"][1]};
                newWeapon.positionOnPlayer = {data2["PositionOnPlayer"][0], data2["PositionOnPlayer"][1]};
                
                newWeapon.shakeIntensity = data2["shakeIntensity"];
                newWeapon.shakeDuration = data2["shakeDuration"];
                
                newWeapon.hasrecoil = data2["hasrecoil"];
                newWeapon.recoilTime = data2["recoilTime"];
                
                nlohmann::json data3 = data2["Bullet"];
                
                newWeapon.bulletSize = {data3["Size"][0], data3["Size"][1]};
                newWeapon.BulletImage = data3["BulletImage"];
                newWeapon.spread = data3["spread"];
                newWeapon.fireRate = data3["fireRate"];
                newWeapon.speed = data3["speed"];
                newWeapon.Bulletquantity = data3["Bulletquantity"];
                newWeapon.damage = data3["damage"];
                newWeapon.lifeTime = data3["lifeTime"];
                
                weapons[data2["Name"]] = newWeapon;
            }
        }   
    }
}