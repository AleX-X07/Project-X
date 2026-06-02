#pragma once
#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <functional>

#include "../../Pattern/Factories.h"

class GameEngine;

class SceneReader {
public:
   SceneReader() = default;
   ~SceneReader() = default;
    
   void loadScene();
   void SceneTestDev();
   void SceneTestDev2();
};
