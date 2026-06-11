#pragma once
// Behaviour
#include "../ECS/Behaviour/AiDebugShoot.h"
#include "../ECS/Behaviour/AiMoveTo.h"

#include "../ECS/Behaviour/Manager/AiMobSpawner.h"

// Box
#include "../ECS/Box/HurtBox.h"
#include "../ECS/Box/HitBox.h"

// Bullet
#include "../ECS/Bullet/BulletLogic/BulletSystemComponent.h"
#include "../ECS/Bullet/BulletLogic/GrenadeSystemComponent.h"

#include "../ECS/Bullet/Special/GrenadeBullet.h"

#include "../ECS/Bullet/BulletManager.h"
#include "../ECS/Bullet/BulletSource.h"

// Graphics
#include "../ECS/Graphics/RenderFile.h"
#include "../ECS/Graphics/RenderText.h"
#include "../ECS/Graphics/RenderColor.h"

#include "../ECS/Graphics/HUD/HUD.h"
#include "../ECS/Graphics/HUD/HealthDisplay.h"
#include "../ECS/Graphics/HUD/TimerDisplay.h"

// Input
#include "../ECS/Input/InputComponent.h"
#include "../ECS/Input/MouseComponent.h"

// Movement
#include "../ECS/Movement/MovementComponent.h"
#include "../ECS/Movement/StateMachineComponent.h"

// Scene
#include "Scene/Transition.h"
#include "Scene/ScreenManager.h"
#include "Scene/Quit.h"

// Tool
#include "../ECS/Tool/CameraComponent.h"
#include "../ECS/Tool/HealthComponent.h"
#include "../ECS/Tool/CrossHairComponent.h"

#include "../ECS/Tool/Debug/DebugHudComp.h"

// Weapon
#include "../ECS/Weapon/WeaponMain.h"