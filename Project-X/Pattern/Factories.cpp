#include "Factories.h"    
#include "../Scene/Scene.h"
#include "../ECS/Object.h"
#include "../ECS/Component.h"
#include "../ECS/Tool/TimerComponent.h"

std::unordered_map <
    std::string,
    ComponentFactory
> FactoriesECS::factories = {
    // Behaviour
    {"AIMobSpawner",    [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new AiMobSpawner(obj, currentScene->getVecObjects());
    }},
    // Box
    {"HurtBox", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new HurtBox(obj, {ecs["args"][0],ecs["args"][1]}, currentScene->getVecObjects(), ecs["args"][2]);
    }},
    // Bullet
    {"BulletManager", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new BulletManager(obj);
    }},
    // Graphics
    {"RenderFile", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        if (ecs.contains("args") && !ecs["args"].empty() && !ecs["args"][0].is_null()) {
            return new RenderFile(obj, ecs["args"][0]);
        }
        return new RenderFile(obj);
    }},
    {"RenderText", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new RenderText(obj, ecs["agrs"][0]); 
    }},
    {"RenderColor", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new RenderColor(obj, {ecs["args"][0], ecs["args"][1], ecs["args"][2], ecs["args"][3]});
    }},
    {"HUD", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new HUD(obj);
    }},
        //HUD
        {"HealthDisplay", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
            return new HealthDisplay(obj, {ecs[1][0], ecs[1][1]}, ecs[2], {ecs[3][0],ecs[3][1],ecs[3][2],ecs[3][3]},ecs[4]);
        }},
        {"TimerDisplay", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
            return new TimerDisplay(obj, {ecs[1][0], ecs[1][1]}, ecs[2], {ecs[3][0],ecs[3][1],ecs[3][2],ecs[3][3]},ecs[4]);
        }},
    // Input
    {"Mouse",    [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new MouseComponent(obj);
    }},
    {"Input",    [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new InputComponent(obj);
    }},
    // Movement
    {"Movement", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new MovementsComponent(obj, ecs["args"][0]);
    }},
    {"StateMachine", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
       return new StateMachineComponent(obj); 
    }},
    
    // Scene
    {"Transition", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        const std::unordered_map<std::string, TransitionType> typeMap = {
            {"Button",  TransitionType::Button},
        };
        return new Transition(obj, ecs["args"][0], typeMap.at(std::string(ecs["args"][1])));
    }},
    {"Quit", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new Quit(obj);
    }},
        //Screen
        {"ScreenWin", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
            return new ScreenWin(obj, currentScene, ecs["args"][0]);
        }},
        {"ScreenDeath", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
            return new ScreenDeath(obj, currentScene, ecs["args"][0]);
        }},
        {"ScreenPaused", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
            return new ScreenPaused(obj, currentScene, ecs["args"][0]);
        }},
        {"ScreenSettings", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
            return new ScreenSettings(obj, currentScene, ecs["args"][0]);
        }},
        {"ScreenClear", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
            return new ScreenClear(obj, currentScene);
        }},
    // Tool
    {"ExpManager", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new ExpManager(obj);
    }},
    {"Camera", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new CameraComponent(obj, ecs["args"][0], ecs["args"][1]);
    }},
    {"Crosshair", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new CrossHairComponent(obj);
    }},
    {"Health", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new HealthComponent(obj, ecs["args"][0], currentScene->getVecObjects());
    }},
    {"Timer", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new TimerComponent(obj, ecs["args"][0]);
    }},
    // Weapon
    {"Weapon", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new WeaponMain(obj, ecs["args"][0]);
    }},
    // Debug
    {"DebugHUD", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new DebugHudComp(obj);
    }},
    // Capacity
{"CapacityManager", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new CapacityManager(obj);
    }}
};

std::unordered_map <
        std::string,
        StateFactory
> FactoriesStates::factories = {
    {"IdleRight", [](Object* obj, mapState myMap) -> State* {
            return new IdleRightState(obj, myMap);
    }},
    {"IdleLeft", [](Object* obj, mapState myMap) -> State* {
            return new IdleLeftState(obj, myMap);
    }},
    {"Right", [](Object* obj, mapState myMap) -> State* {
            return new RightState(obj, myMap);
    }},
    {"Left", [](Object* obj, mapState myMap) -> State* {
            return new LeftState(obj, myMap);
    }}
};
