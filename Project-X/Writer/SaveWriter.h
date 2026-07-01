#pragma once
#include <nlohmann/json.hpp>
#include <fstream>

class SaveWriter {
private:
    static SaveWriter* myInstance;
    std::string pathSave;
    
    std::unordered_map<std::string, bool> weaponUnlock;
    
    SaveWriter();
    
public:
    ~SaveWriter();
    
    static SaveWriter* getInstance();
    
    void writeGold(int gold);
    
    void writeWeapon();
    
    int readGold();
    std::unordered_map<std::string, bool>& getWeaponUnlock();
    
    void clearSave();
};
