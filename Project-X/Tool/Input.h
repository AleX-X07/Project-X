#pragma once
#include "SFMl/Graphics.hpp"

using InputMap = std::unordered_map<std::string, sf::Keyboard::Key>;

class Input {
private:
    static Input* myInstance;

    InputMap inputMap;
    
private:
    Input();
    
public:
    static Input* getInput();
    
    ~Input() = default;
    
    InputMap& getMap();
    sf::Keyboard::Key getKey(const std::string& key);
};
