#include "ScriptParser.h"
#include <fstream>
#include <sstream>
#include <iterator>
#include <iostream>

void ScriptParser::LoadFile(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "[Script] Fichier introuvable: " << path << "\n";
        return;
    }
    std::cerr << "[Script] Fichier chargé: " << path << "\n";
    
    std::string   currentEvent = "";
    std::string   line;

    while (std::getline(file, line)) {
        line = Trim(line);
        if (line.empty() || line[0] == '#') continue;

        if (line.rfind("NAME", 0) == 0)     { name     = Split(line)[1]; continue; }
        if (line.rfind("COOLDOWN", 0) == 0) { cooldown = stof(Split(line)[1]); continue; }
        if (line.rfind("ON_", 0) == 0)      { currentEvent = line; continue; }

        if (!currentEvent.empty()) {
            auto tokens = Split(line);
            Command cmd;
            cmd.instruction = tokens[0];
            cmd.args = { tokens.begin() + 1, tokens.end() };
            events[currentEvent].push_back(cmd);
        }
    }
}

std::vector<std::string> ScriptParser::Split(const std::string& s) {
    std::istringstream iss(s);
    return { std::istream_iterator<std::string>{iss},
             std::istream_iterator<std::string>{} };
}

std::string ScriptParser::Trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \t");
    size_t end   = s.find_last_not_of(" \t");
    return (start == std::string::npos) ? "" : s.substr(start, end - start + 1);
}