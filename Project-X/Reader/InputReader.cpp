#include "InputReader.h"

InputReader* InputReader::myInstance = nullptr;

InputReader::~InputReader() {
    delete myInstance;
    myInstance = nullptr;
}

void InputReader::read() {
    std::ifstream inputFile("Data/Input/Input.json");
    if (inputFile.is_open()) {
        nlohmann::json data = nlohmann::json::parse(inputFile);
        for (auto& [key,val] : data.items()) {
            Input::getInput()->getMap()[key] = keyTable.at(val.get<std::string>());
        }
    }
}

InputReader* InputReader::getInstance() {
    if (myInstance == nullptr) {
        myInstance = new InputReader();
    }
    return myInstance;
}
