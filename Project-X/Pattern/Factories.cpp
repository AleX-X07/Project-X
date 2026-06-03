#include "Factories.h"
#include "../Scene/Scene.h"
#include "../ECS/Object.h"
#include "../ECS/Component.h"

std::unordered_map <
    std::string,
    ComponentFactory
> Factories::factories = {
    {"Render",   [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new RenderComponent(obj, ecs["args"][0]);
    }},
    {"Mouse",    [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new MouseComponent(obj);
    }},
    {"Input",    [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new InputComponent(obj);
    }},
    {"Movement", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new movementsComponent(obj, ecs["args"][0], {ecs["args"][1],ecs["args"][2] });
    }},
    {"HurtBox", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new HurtBox(obj, {ecs["args"][0],ecs["args"][1]}, currentScene->getVecObjects(), ecs["args"][2]);
    }},
    {"HitBox", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new HitBox(obj, {ecs["args"][0],ecs["args"][1]} , ecs["args"][2]);
    }},
    {"BulletManager", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new BulletManager(obj);
    }},
    {"BulletSystemComponent", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new BulletSystemComponent(obj, ecs["args"][0], ecs["args"][1], ecs["args"][2], ecs["args"][3]);
    }},
};