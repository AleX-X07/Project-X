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
private:
   static std::unordered_map<std::string, Scene*> scenesHUD;
public:
   SceneReader() = default;
   virtual ~SceneReader() override = default;
   
   virtual void read() override;
   void readAnimation(nlohmann::basic_json<>& ecs, Object* newObj);
   void readSceneHUD(std::string file);
   void readHUD(nlohmann::basic_json<>& ecs, Object* newObj, Scene* newScene);
   
   void SceneTestDev();
   void SceneTestDev2();
   
   static std::unordered_map<std::string, Scene*>& getScenes();
};
