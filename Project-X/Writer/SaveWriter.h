#pragma once
#include <nlohmann/json.hpp>
#include <fstream>

class SaveWriter {
private:
    static SaveWriter* myInstance;
    SaveWriter()  = default;
public:
    ~SaveWriter() = default;
    
    static SaveWriter* getInstance();
    
    void writeGold(int gold);
    int readGold();
};
