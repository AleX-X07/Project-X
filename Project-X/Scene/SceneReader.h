#pragma once
#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>

#include "../ECS/MovementComponent.h"
#include "../ECS/RenderComponent.h"
#include "../ECS/InputComponent.h"
#include "../ECS/BulletSystemComponent.h"
#include "../ECS/MouseComponent.h"
#include "../ECS/BulletManager.h"

#include "Scene.h"

class GameEngine;

class SceneReader {

public:
   SceneReader() = default;
   ~SceneReader() = default;
    
   void loadScene();
   void SceneTestDev();
};
