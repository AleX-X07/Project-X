#include "CapacityMain.h"
#include <iostream>

#include "../Bullet/BulletManager.h"
#include "../Weapon/WeaponMain.h"

CapacityMain::CapacityMain(Object* _owner, const std::string& path) : Component(_owner) {
    script.LoadFile(path);
}

void CapacityMain::Activate() {
    if (cooldownTimer > 0) return;
    cooldownTimer = script.cooldown;
    RunEvent("ON_ACTIVATE");
}

void CapacityMain::update(float dt) {
    if (cooldownTimer > 0) cooldownTimer -= dt;
    RunEvent("ON_UPDATE");
}

void CapacityMain::render() {
    RunEvent("ON_RENDER");
}

void CapacityMain::RunEvent(const std::string& eventName) {
    if (!script.events.count(eventName)) return;
    for (auto& cmd : script.events[eventName])
        Execute(cmd);
}

void CapacityMain::Execute(const Command& cmd) {
    const auto& c = cmd.instruction;
    const auto& a = cmd.args;

    if      (c == "SPAWN_PROJECTILE") SpawnProjectile(stof(a[0]), stof(a[1]), stof(a[2]), stof(a[3]), stof(a[4]));
    else if (c == "PLAY_SOUND")       PlaySound(a[0]);
    else if (c == "CHECK_COLLISIONS") CheckCollisions();
    else if (c == "DRAW_PROJECTILES") DrawProjectiles(a[0]);
    else
        std::cerr << "[Script] Commande inconnue: " << c << "\n";
}

void CapacityMain::SpawnProjectile(float size, float rad, float speed, float lifetime, int damage) {
    auto comp = owner->getComponent<BulletManager>();
    if (comp) {
        Object* ball = new Object(owner->getPosition(), {size, size});
    
        ball->addComponent(new BulletSystemComponent(ball, speed, rad, lifetime));
        ball->addComponent(new RenderComponent(ball, "Assets/Debug/DebugBulletblue.png"));
        ball->addComponent(new HitBox(ball, {size, size}, true, damage));
    
        comp->bullet.push_back(ball);
    }
}

void CapacityMain::PlaySound(const std::string& file) {
    if (buffer.loadFromFile(file)) {
        sound.setBuffer(buffer);
        sound.play();
    } else {
        std::cerr << "[Script] Son introuvable: " << file << "\n";
    }
}

void CapacityMain::CheckCollisions() {
    
}

void CapacityMain::DrawProjectiles(const std::string& color) {
    
}