#pragma once
#include <nlohmann/json.hpp>
#include <fstream>

class SaveWriter {
private:
    static SaveWriter* myInstance;
    std::string pathSave;
    
    std::unordered_map<std::string, bool> weaponUnlock;
    std::unordered_map<std::string, bool> capaUnlock;
    
    SaveWriter();
    
public:
    ~SaveWriter();
    
    static SaveWriter* getInstance();
    
    void writeGold(int gold);
    
    void writeWeapon();
    void writeCapa();
    
    int readGold();
    std::unordered_map<std::string, bool>& getWeaponUnlock();
    std::unordered_map<std::string, bool>& getCapaUnlock();
    
    void clearSave();
};
