#include "ParticleSystem.h"
#include "../../Main/GameEngine.h"

ParticleSystem::ParticleSystem(sf::Vector2f _pos, sf::Vector2f _size, float _angle, float _speed, float _lifetime, sf::Color Color) {
    pos = _pos;
    size = _size;
    angle = _angle;
    lifetime = _lifetime;
    speed = _speed;
    
    rect.setFillColor(Color);
    rect.setPosition(pos);
    rect.setSize(size);
}

ParticleSystem::~ParticleSystem() {
    
}

void ParticleSystem::update(float dt) {
    pos.x += cos(angle) * speed * dt;
    pos.y += sin(angle) * speed * dt;
    
    rect.setPosition(pos);
    
    actualTime += dt;
    if (actualTime >= lifetime) {
        IsAlive = false;
    }
}

void ParticleSystem::render() {
    GameEngine::getWindow()->draw(rect);
}
