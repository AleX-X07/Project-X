#pragma once
#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <functional>

#include "../ECS/MovementComponent.h"
#include "../ECS/RenderComponent.h"
#include "../ECS/InputComponent.h"

#include "../ECS/MouseComponent.h"

#include "../ECS/BulletSystemComponent.h"
#include "../ECS/BulletManager.h"


#include "Scene.h"

class GameEngine;
using ComponentFactory = std::function<Component*(Object*, const nlohmann::json&, Scene*)>;

class SceneReader {
private:
   static std::unordered_map <
        std::string,
        ComponentFactory
    > factories;
    
public:
   SceneReader() = default;
   ~SceneReader() = default;
    
   void loadScene();
   void SceneTestDev();
};
