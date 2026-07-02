#include "CapacityReader.h"
#include "../ECS/Object.h"

CapacityReader* CapacityReader::myInstance = nullptr;

CapacityReader::~CapacityReader() {
    delete myInstance;
    myInstance = nullptr;
}

std::unordered_map<std::string, std::string>& CapacityReader::getCapacity() {
    return capacity;
}

std::unordered_map<std::string, int>& CapacityReader::getCapacityPrice() {
    return capacityPrice;
}

void CapacityReader::read() {
    std::string path = "Data/Capacity/CapacityManager.json";
    std::ifstream file(path);
    
    if (file.is_open()) {
        nlohmann::json data = nlohmann::json::parse(file);
        std::string path = "Assets/Capacity/";
        for (auto& [key, value] : data["Capacity"].items()) {
            capacity[key] = path + value[0].get<std::string>();
            capacityPrice[key] = value[1].get<int>();
        }
    }
}

CapacityMain* CapacityReader::readCapacity(Object* owner, std::string _capa) {
    std::ifstream file("Data/Capacity/Capacity.json");
    if (file.is_open()) {
        nlohmann::json data = nlohmann::json::parse(file);
        for (auto& [key, value] : data["Capacity"].items()) {
            if (key == _capa) {
                return FactoriesCapacity::factories[_capa](owner, value);
            }
        }
    }
    return nullptr;
}

CapacityReader* CapacityReader::getInstance() {
    if (myInstance == nullptr) {
        myInstance = new CapacityReader();
    }
    return myInstance;
}
