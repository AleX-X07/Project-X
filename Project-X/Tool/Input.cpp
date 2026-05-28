#include "Input.h"

#include "SFML/Window/Event.hpp"

Input* Input::myInstance = nullptr;

InputMap& Input::getMap() {
    return inputMap;
}

sf::Keyboard::Key Input::getKey(const std::string& key) {
    auto it = inputMap.find(key);
    if (it != inputMap.end()) {
        return it->second;
    }
    return sf::Keyboard::Key::Unknown;
}

Input::Input() {
    myInstance = nullptr;
}

Input* Input::getInput() {
    if (myInstance == nullptr) {
        myInstance = new Input();
    }
    return myInstance;
}
