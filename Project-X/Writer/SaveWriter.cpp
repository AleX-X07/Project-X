#include "SaveWriter.h"

#include "../Reader/WeaponReader.h"

SaveWriter* SaveWriter::myInstance = nullptr;

SaveWriter::SaveWriter() {
    pathSave = "Data/Save/Save.json";
    if (!std::filesystem::exists(pathSave)) {
        std::filesystem::create_directories(std::filesystem::path(pathSave).parent_path());
        nlohmann::json data = nlohmann::json::object();
        std::ofstream outFile(pathSave);
        data["Gold"] = 0;
        for (auto& [k,v] : WeaponReader::getInstance()->getWeapons()) {
            data[k] = false;
        }
        if (outFile.is_open()) {
            outFile << data.dump(4);
            outFile.close();
        }
    }
    std::ifstream inFile(pathSave);
    nlohmann::json data;
    if (inFile.is_open()) {
        data = nlohmann::json::parse(inFile);
        for (auto& [k,v] : data.items()) {
            if (k != "Gold") {
                getWeaponUnlock()[k] = v.get<bool>();
            }
        }
    }
}

SaveWriter::~SaveWriter() {
    delete myInstance;
    myInstance = nullptr;
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
        data[k] = v;
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
}

std::unordered_map<std::string, bool>& SaveWriter::getWeaponUnlock() {
    return weaponUnlock;
}

void SaveWriter::clearSave() {
    std::ofstream outFile(pathSave);
    if (outFile.is_open()) {
        nlohmann::json data = nlohmann::json::object();
        outFile << data.dump(4);
        outFile.close();
    }
}
