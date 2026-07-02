#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

#include "nlohmann/json.hpp"

#include "Reader.h"
#include "../Pattern/Factories.h"

class Object;

class CapacityReader : public Reader {
private:
    static CapacityReader* myInstance;
    
    std::unordered_map<std::string, std::string> capacity; 
    std::unordered_map<std::string, int> capacityPrice;
    
    CapacityReader() = default;
    
public:
    virtual ~CapacityReader() override;
    
    std::unordered_map<std::string, std::string>& getCapacity();
    std::unordered_map<std::string, int>& getCapacityPrice();
    
    virtual void read() override;
    
    CapacityMain* readCapacity(Object* owner, std::string _capa);
    
    static CapacityReader* getInstance();
};
