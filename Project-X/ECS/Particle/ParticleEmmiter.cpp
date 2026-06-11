#include "ParticleEmmiter.h"

ParticleEmmiter::ParticleEmmiter(sf::Vector2f _pos, sf::Vector2f _size, int _quantity, int _burstquantity) {
    pos = _pos;
    size = _size;
    quantity = _quantity;
    burstquantity = _burstquantity;
    
    std::srand(std::time(nullptr));
}

ParticleEmmiter::~ParticleEmmiter() {
    ParticleList.clear();
}

void ParticleEmmiter::update(float deltaTime) {
    for (auto& c : ParticleList) {
        c->update(deltaTime);
    }
    
    
    ParticleList.erase(
        std::remove_if(ParticleList.begin(), ParticleList.end(), [](const std::unique_ptr<ParticleSystem>& b) {
                return !b->IsAlive;
            }),
        ParticleList.end()
    );
    
    if (burstquantity == 0 && ParticleList.empty()) {
        isAlive = false;
    }
}

void ParticleEmmiter::render() {
    for (auto& c : ParticleList) {
        c->render();
    }
}

void ParticleEmmiter::Burst() {
    if (burstquantity != 0) {
        for (int i = 0; i < quantity; i ++) {
            float angle = std::rand() % 361;
            float rad = angle * 3.14 / 180;
            
            ParticleList.push_back(std::make_unique<ParticleSystem>(pos, size, rad, 500, 0.1, sf::Color{255, 0, 0, 255}));
        }
        burstquantity -= 1;
    }
}
