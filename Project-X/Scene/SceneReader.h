#pragma once
#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <functional>

#include "../ECS/Movement/MovementComponent.h"
#include "../ECS/Graphics/RenderComponent.h"
#include "../ECS/Input/InputComponent.h"
#include "../ECS/Tool/CameraComponent.h"

#include "../ECS/Input/MouseComponent.h"

#include "../ECS/Bullet/BulletSystemComponent.h"
#include "../ECS/Bullet/BulletManager.h"


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
