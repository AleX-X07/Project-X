#pragma once

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <functional>

#include "nlohmann/json.hpp"

#include "../../Tool/Input.h"

class InputReader {
private:
    const std::unordered_map<std::string, sf::Keyboard::Key> keyTable = {
        // Lettres
        {"A", sf::Keyboard::Key::A}, {"B", sf::Keyboard::Key::B}, {"C", sf::Keyboard::Key::C},
        {"D", sf::Keyboard::Key::D}, {"E", sf::Keyboard::Key::E}, {"F", sf::Keyboard::Key::F},
        {"G", sf::Keyboard::Key::G}, {"H", sf::Keyboard::Key::H}, {"I", sf::Keyboard::Key::I},
        {"J", sf::Keyboard::Key::J}, {"K", sf::Keyboard::Key::K}, {"L", sf::Keyboard::Key::L},
        {"M", sf::Keyboard::Key::M}, {"N", sf::Keyboard::Key::N}, {"O", sf::Keyboard::Key::O},
        {"P", sf::Keyboard::Key::P}, {"Q", sf::Keyboard::Key::Q}, {"R", sf::Keyboard::Key::R},
        {"S", sf::Keyboard::Key::S}, {"T", sf::Keyboard::Key::T}, {"U", sf::Keyboard::Key::U},
        {"V", sf::Keyboard::Key::V}, {"W", sf::Keyboard::Key::W}, {"X", sf::Keyboard::Key::X},
        {"Y", sf::Keyboard::Key::Y}, {"Z", sf::Keyboard::Key::Z},

        // Chiffres (rangée du haut)
        {"0", sf::Keyboard::Key::Num0}, {"1", sf::Keyboard::Key::Num1}, {"2", sf::Keyboard::Key::Num2},
        {"3", sf::Keyboard::Key::Num3}, {"4", sf::Keyboard::Key::Num4}, {"5", sf::Keyboard::Key::Num5},
        {"6", sf::Keyboard::Key::Num6}, {"7", sf::Keyboard::Key::Num7}, {"8", sf::Keyboard::Key::Num8},
        {"9", sf::Keyboard::Key::Num9},

        // Pavé numérique
        {"Numpad0", sf::Keyboard::Key::Numpad0}, {"Numpad1", sf::Keyboard::Key::Numpad1},
        {"Numpad2", sf::Keyboard::Key::Numpad2}, {"Numpad3", sf::Keyboard::Key::Numpad3},
        {"Numpad4", sf::Keyboard::Key::Numpad4}, {"Numpad5", sf::Keyboard::Key::Numpad5},
        {"Numpad6", sf::Keyboard::Key::Numpad6}, {"Numpad7", sf::Keyboard::Key::Numpad7},
        {"Numpad8", sf::Keyboard::Key::Numpad8}, {"Numpad9", sf::Keyboard::Key::Numpad9},

        // Touches de direction
        {"Up", sf::Keyboard::Key::Up}, {"Down", sf::Keyboard::Key::Down},
        {"Left", sf::Keyboard::Key::Left}, {"Right", sf::Keyboard::Key::Right},

        // Touches de fonction
        {"F1",  sf::Keyboard::Key::F1},  {"F2",  sf::Keyboard::Key::F2},
        {"F3",  sf::Keyboard::Key::F3},  {"F4",  sf::Keyboard::Key::F4},
        {"F5",  sf::Keyboard::Key::F5},  {"F6",  sf::Keyboard::Key::F6},
        {"F7",  sf::Keyboard::Key::F7},  {"F8",  sf::Keyboard::Key::F8},
        {"F9",  sf::Keyboard::Key::F9},  {"F10", sf::Keyboard::Key::F10},
        {"F11", sf::Keyboard::Key::F11}, {"F12", sf::Keyboard::Key::F12},

        // Modificateurs
        {"LShift",   sf::Keyboard::Key::LShift},   {"RShift",   sf::Keyboard::Key::RShift},
        {"LControl", sf::Keyboard::Key::LControl}, {"RControl", sf::Keyboard::Key::RControl},
        {"LAlt",     sf::Keyboard::Key::LAlt},     {"RAlt",     sf::Keyboard::Key::RAlt},

        // Touches spéciales
        {"Space",     sf::Keyboard::Key::Space},
        {"Enter",     sf::Keyboard::Key::Enter},
        {"Escape",    sf::Keyboard::Key::Escape},
        {"Backspace", sf::Keyboard::Key::Backspace},
        {"Tab",       sf::Keyboard::Key::Tab},
    };
public:
    InputReader() = default;
    ~InputReader() = default;
    
    void loadInput();
};
