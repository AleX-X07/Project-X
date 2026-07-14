#include "SaveWriter.h"

#include "../Reader/CapacityReader.h"
#include "../Reader/WeaponReader.h"

SaveWriter* SaveWriter::myInstance = nullptr;

SaveWriter::SaveWriter() {
    pathSave = "Data/Save/Save.json";
    if (!std::filesystem::exists(pathSave)) {
        std::filesystem::create_directories(std::filesystem::path(pathSave).parent_path());
        nlohmann::json data = nlohmann::json::object();
        std::ofstream outFile(pathSave);
        data["Gold"] = 0;
        nlohmann::json& data2 = data["Weapon"];
        for (auto& [k,v] : WeaponReader::getInstance()->getWeapons()) {
            data2[k] = false;
        }
        nlohmann::json& data3 = data["Capacity"];
        for (auto& [k,v] : CapacityReader::getInstance()->getCapacity()) {
            data3[k] = false;
        }
        if (outFile.is_open()) {
            outFile << data.dump(4);
            outFile.close();
        }
    }
    std::ifstream inFile(pathSave);
    if (inFile.is_open()) {
        nlohmann::json data = nlohmann::json::parse(inFile);
        for (auto& [k, v] : data["Weapon"].items()) {
            weaponUnlock[k] = v.get<bool>();
        }
        for (auto& [k,v] : data["Capacity"].items()) {
            capaUnlock[k] = v.get<bool>();
        }
        inFile.close();
    }
}

SaveWriter::~SaveWriter() {
    capaUnlock.clear();
    weaponUnlock.clear();
}

SaveWriter* SaveWriter::getInstance() {
    if (myInstance == nullptr) {
        myInstance = new SaveWriter();
    }
    return myInstance;
}

void SaveWriter::writeGold(int gold) {
    std::ifstream inFile(pathSave);
    nlohmann::json data;
    if (inFile.is_open()) {
        data = nlohmann::json::parse(inFile);
        inFile.close();
    }
    data["Gold"] = data["Gold"].get<int>() + gold;
    std::ofstream outFile(pathSave);
    if (outFile.is_open()) {
        outFile << data.dump(4);
    }
}

void SaveWriter::writeWeapon() {
    std::ifstream inFile(pathSave);
    nlohmann::json data;
    if (inFile.is_open()) {
        data = nlohmann::json::parse(inFile);
        inFile.close();
    }

    for (auto& [k, v] : weaponUnlock) {
        data["Weapon"][k] = v;
    }

    std::ofstream outFile(pathSave);
    if (outFile.is_open()) {
        outFile << data.dump(4);
        outFile.close();
    }
}

void SaveWriter::writeCapa() {
    std::ifstream inFile(pathSave);
    nlohmann::json data;
    if (inFile.is_open()) {
        data = nlohmann::json::parse(inFile);
        inFile.close();
    }

    for (auto& [k, v] : capaUnlock) {
        data["Capacity"][k] = v;
    }

    std::ofstream outFile(pathSave);
    if (outFile.is_open()) {
        outFile << data.dump(4);
        outFile.close();
    }
}

int SaveWriter::readGold() {
    std::ifstream inFile(pathSave);
    nlohmann::json data;
    if (inFile.is_open()) {
        data = nlohmann::json::parse(inFile);
        return data["Gold"].get<int>();
    }
    return 0;
}

std::unordered_map<std::string, bool>& SaveWriter::getWeaponUnlock() {
    return weaponUnlock;
}

std::unordered_map<std::string, bool>& SaveWriter::getCapaUnlock() {
    return capaUnlock;
}

void SaveWriter::clearSave() {
    for (auto& [k, v] : weaponUnlock) {
        v = false;
    }
    for (auto& [k, v] : capaUnlock) {
        v = false;
    }

    nlohmann::json data = nlohmann::json::object();
    data["Gold"] = 0;

    nlohmann::json& dataWeapon = data["Weapon"];
    for (auto& [k, v] : weaponUnlock) {
        dataWeapon[k] = false;
    }

    nlohmann::json& dataCapa = data["Capacity"];
    for (auto& [k, v] : capaUnlock) {
        dataCapa[k] = false;
    }

    std::ofstream outFile(pathSave);
    if (outFile.is_open()) {
        outFile << data.dump(4);
        outFile.close();
    }
    
    std::ofstream file("Data/Stat/Stat.txt", std::ios::out);
    
    
    file << 1 << "\n";
    file << 1 << "\n";
    file << 1 << "\n";
    file << 1 << "\n";
    file << 1 << "\n";
    
    file.close();
}

