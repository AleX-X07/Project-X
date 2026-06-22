#include "GoldComponent.h"

#include "GoldManager.h"

GoldComponent::GoldComponent(Object* _owner, sf::Vector2f _size, std::vector<Object*>& _objects, int _quantity) : Component(_owner), other(_objects) {
    size = _size;
    pos = owner->getPosition();
    quantity = _quantity;
    isActive = true;
    
    buffer.loadFromFile("Assets/Sound/ExpPickup.wav");
    sound = new sf::Sound(buffer);
}

void GoldComponent::update(float dt) {
    intersect();
}

void GoldComponent::intersect() {
    for (auto b : other)
    {
        if (b == owner) continue;
        if (b->team == owner->team) continue;
        
        if (b->team != owner->team && b->team == Object::Team::Player)
        {
            if (overlaps(b) && isActive) {
                auto comp = b->getComponent<GoldManager>();
                if (comp != nullptr) {
                    comp->setGold(comp->getGold() + quantity);
                    sound->play();
                    isActive = false;
                }
            }
        }
    }
}

bool GoldComponent::overlaps(Object* hit) {
    return hit->getPosition().x < pos.x + size.x &&
           hit->getPosition().x + hit->getSize().x > pos.x &&
           hit->getPosition().y < pos.y + size.y &&
           hit->getPosition().y + hit->getSize().y > pos.y;
}