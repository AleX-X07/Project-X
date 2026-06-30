#include "SaveWriter.h"

SaveWriter* SaveWriter::myInstance = nullptr;

SaveWriter* SaveWriter::getInstance() {
    if (myInstance == nullptr) {
        myInstance = new SaveWriter();
    }
    return myInstance;
}

void SaveWriter::writeGold(int gold) {
    std::ifstream inFile("Data/Save/Save.json");
    nlohmann::json data;
    if (inFile.is_open()) {
        data = nlohmann::json::parse(inFile);
        inFile.close();
    }
    if (data["Gold"].is_null()) {
        data["Gold"] = 0;
    }
    data["Gold"] = data["Gold"].get<int>() + gold;
    std::ofstream outFile("Data/Save/Save.json");
    if (outFile.is_open()) {
        outFile << data.dump(4);
    }
}

int SaveWriter::readGold() {
    std::ifstream inFile("Data/Save/Save.json");
    nlohmann::json data;
    if (inFile.is_open()) {
        data = nlohmann::json::parse(inFile);
        return data["Gold"].get<int>();
    }
}
