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
#include "../../ECS/Bullet/BulletSystemComponent.h"
#include "../../ECS/Bullet/BulletManager.h"
#include "../../ECS/Box/HurtBox.h"
#include "../../ECS/Box/HitBox.h"
#include "../../ECS/Behaviour/AiDebugShoot.h"
#include "../../ECS/Tool/CameraComponent.h"
#include "../../ECS/Behaviour/Manager/AiMobSpawner.h"

#include "../Scene.h"


class GameEngine;

class SceneReader {
public:
   SceneReader() = default;
   ~SceneReader() = default;
    
   void loadScene();
   void SceneTestDev();
};
