#pragma once
#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>

#include "../ECS/MovementComponent.h"
#include "../ECS/RenderComponent.h"
#include "../ECS/InputComponent.h"

#include "Scene.h"

class GameEngine;

class SceneReader {
public:
public:
public:
   SceneReader() = default;
   ~SceneReader() = default;
    
   void loadScene();
   void SceneTestDev();
};
