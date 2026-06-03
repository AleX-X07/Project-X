#pragma once
#include <functional>
#include <string>
#include <nlohmann/json.hpp>


#include "../ECS/IncludeECS.h"

#include "../Pattern/StateMachine/IncludeSM.h"


class Scene;
class Component;
class Object;


using ComponentFactory = std::function<Component*(Object*, const nlohmann::json&, Scene*)>;

using mapState = std::unordered_map<std::string,nlohmann::json>*;
using StateFactory = std::function<State*(Object*, mapState)>;


struct FactoriesECS {
    static std::unordered_map <
        std::string,
        ComponentFactory
    > factories;
};


struct FactoriesStates {
    static std::unordered_map <
        std::string,
        StateFactory
    > factories;
};

