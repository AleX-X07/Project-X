#include "Factories.h"    
#include "../Scene/Scene.h"
#include "../ECS/Object.h"
#include "../ECS/Component.h"

std::unordered_map <
    std::string,
    ComponentFactory
> FactoriesECS::factories = {
    {"Render", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        if (ecs.contains("args") && !ecs["args"].empty() && !ecs["args"][0].is_null()) {
            return new RenderComponent(obj, ecs["args"][0]);
        }
        return new RenderComponent(obj);
    }},
    {"Mouse",    [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new MouseComponent(obj);
    }},
    {"Input",    [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new InputComponent(obj);
    }},
    {"Movement", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new MovementsComponent(obj, ecs["args"][0]);
    }},
    {"HurtBox", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new HurtBox(obj, {ecs["args"][0],ecs["args"][1]}, currentScene->getVecObjects(), ecs["args"][2]);
    }},
    {"HitBox", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new HitBox(obj, {ecs["args"][0],ecs["args"][1]} , ecs["args"][2], ecs["args"][2]);
    }},
    {"BulletManager", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new BulletManager(obj);
    }},
    {"BulletSystem", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new BulletSystemComponent(obj, ecs["args"][0], ecs["args"][1], ecs["args"][2]);
    }},
    {"StateMachine", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
       return new StateMachineComponent(obj); 
    }},
};

std::unordered_map <
        std::string,
        StateFactory
> FactoriesStates::factories = {
    {
        "IdleRight", [](Object* obj, mapState myMap) -> State* {
            return new IdleRightState(obj, myMap);
        }
    },
    {
        "IdleLeft", [](Object* obj, mapState myMap) -> State* {
            return new IdleLeftState(obj, myMap);
        }
    },
    {
        "Right", [](Object* obj, mapState myMap) -> State* {
            return new RightState(obj, myMap);
        }
    },
    {
        "Left", [](Object* obj, mapState myMap) -> State* {
            return new LeftState(obj, myMap);
        }
    }
};