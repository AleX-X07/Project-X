#pragma once
#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <functional>

#include "../../Pattern/Factories.h"

#include "../../ECS/Movement/MovementComponent.h"
#include "../../ECS/Graphics/RenderComponent.h"
#include "../../ECS/Input/InputComponent.h"
#include "../../ECS/Input/MouseComponent.h"
#include "../../ECS/Bullet/BulletLogic/BulletSystemComponent.h"
#include "../../ECS/Bullet/BulletManager.h"
#include "../../ECS/Box/HurtBox.h"
#include "../../ECS/Box/HitBox.h"
#include "../../ECS/Behaviour/AiDebugShoot.h"
#include "../../ECS/Tool/CameraComponent.h"
#include "../../ECS/Behaviour/Manager/AiMobSpawner.h"
#include "../../Ecs/Tool/Debug/DebugHudComp.h"

#include "../../ECS/Weapon/Derived/.h/PistolDebug.h"
#include "../../ECS/Weapon/Derived/.h/ShotGun.h"
#include "../../ECS/Weapon/Derived/.h/LaserGun.h"
#include "../../ECS/Weapon/Derived/.h/Ak.h"
#include "../../ECS/Weapon/Derived/.h/GrenadeLauncher.h"
#include "../../ECS/Tool/Experience/ExpManager.h"

#include "../Scene.h"


class GameEngine;

class SceneReader {
public:
   SceneReader() = default;
   ~SceneReader() = default;
   
   void loadScene();
   void readAnimation(nlohmann::basic_json<>& ecs, Object* newObj);
   
   void SceneTestDev();
   void SceneTestDev2();
};
