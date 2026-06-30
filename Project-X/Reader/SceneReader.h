#pragma once
#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <functional>

#include "../Pattern/Factories.h"

#include "../ECS/Tool/Experience/ExpManager.h"
#include "../ECS/Tool/CrossHairComponent.h"
#include "../Gameplay/CapacityManager.h"

#include "../ECS/IncludeECS.h"

#include "../Scene/Scene.h"
#include "Reader.h"
#include "InputReader.h"
#include "../Pattern/StateMachine/StateMachine.h"
#include "WeaponReader.h"
#include "../Tool/MapMaker.h"


class GameEngine;

class SceneReader : public Reader {
private:
   static SceneReader* myInstance;
   
   SceneReader() = default;
public:
   virtual ~SceneReader() override;
   
   virtual void read() override;
   void readScene();
   
   Scene* initScene(int idScene);
   std::vector<Object*>* initScreen(std::string nameScreen, Scene* currentScene);
   
   void makeMap(MapMakeComponent* map, Object* newObj);
   void readAnimation(nlohmann::basic_json<>& ecs, Object* newObj);
   void readHUD(nlohmann::basic_json<>& ecs, Object* newObj, Scene* newScene);
   
   void SceneTestDev();
   
   static SceneReader* getInstance();
};
