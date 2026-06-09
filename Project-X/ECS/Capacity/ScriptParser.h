#pragma once
#include <string>
#include <vector>
#include <unordered_map>

struct Command {
    std::string              instruction;
    std::vector<std::string> args;
};

class ScriptParser {
public:
    std::string name;
    float       cooldown = 1.0f;
    std::unordered_map<std::string, std::vector<Command>> events;

    void LoadFile(const std::string& path);

private:
    std::vector<std::string> Split(const std::string& s);
    std::string              Trim(const std::string& s);
};