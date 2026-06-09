#pragma once
#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <functional>

#include "../Pattern/Factories.h"

#include "../ECS/IncludeECS.h"

#include "../Scene/Scene.h"
#include "Reader.h"


class GameEngine;

class SceneReader : public Reader {
public:
   SceneReader() = default;
   virtual ~SceneReader() override = default;
   
   virtual void read() override;
   void readAnimation(nlohmann::basic_json<>& ecs, Object* newObj);
   
   void SceneTestDev();
   void SceneTestDev2();
};
