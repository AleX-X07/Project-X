#include "InputReader.h"

void InputReader::loadInput() {
    std::ifstream inputFile("Data/Input.json");
    if (inputFile.is_open()) {
        nlohmann::json data = nlohmann::json::parse(inputFile);
        for (auto& [key,val] : data.items()) {
            Input::getInput()->getMap()[key] = keyTable.at(val.get<std::string>());
        }
    }
}
