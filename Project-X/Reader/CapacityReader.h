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
    
    CapacityReader() = default;
    
public:
    virtual ~CapacityReader() override = default;
    
    std::unordered_map<std::string, std::string>& getCapacity();
    
    virtual void read() override;
    
    CapacityMain* readCapacity(Object* owner, std::string _capa);
    
    static CapacityReader* getInstance();
};
