#pragma once
#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <functional>

#include "../Pattern/Factories.h"

#include "../ECS/Movement/MovementComponent.h"
#include "../ECS/Graphics/RenderComponent.h"
#include "../ECS/Input/InputComponent.h"
#include "../ECS/Input/MouseComponent.h"
#include "../ECS/Bullet/BulletLogic/BulletSystemComponent.h"
#include "../ECS/Bullet/BulletManager.h"
#include "../ECS/Box/HurtBox.h"
#include "../ECS/Box/HitBox.h"
#include "../ECS/Behaviour/AiDebugShoot.h"
#include "../ECS/Tool/CameraComponent.h"
#include "../ECS/Behaviour/Manager/AiMobSpawner.h"
#include "../Ecs/Tool/Debug/DebugHudComp.h"

#include "../ECS/Tool/Experience/ExpManager.h"
#include "../ECS/Tool/CrossHairComponent.h"
#include "../ECS/Tool/LevelEnder.h"
#include "../ECS/Capacity/CapacityMain.h"

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
