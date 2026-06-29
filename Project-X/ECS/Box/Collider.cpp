#include "Collider.h"

#include "../../Main/GameEngine.h"
#include "../Movement/MovementComponent.h"

Collider::Collider(Object* _owner, std::vector<Object*>& _objects) : Component(_owner), other(_objects) {
    pos = owner->getPosition();
    size = owner->getSize();
    
    rect.setPosition(pos);
    rect.setSize(size);
    TX.loadFromFile("Assets/Debug/Collider_DebugTX.png");
    rect.setTexture(&TX);
}

void Collider::update(float dt) {
    for (auto c : other) {
        auto comp = c->getComponent<MovementsComponent>();
        if (comp) {
            collisionHori(c);
            collisionVert(c);
        }
    }
}

bool Collider::intersects(Object* object) {
    return object->getPosition().x < pos.x + size.x &&
           object->getPosition().x + object->getSize().x > pos.x &&
           object->getPosition().y < pos.y + size.y &&
           object->getPosition().y + object->getSize().y > pos.y;
}

void Collider::collisionHori(Object* object) {
    sf::FloatRect playerRect(object->getPosition(),  object->getSize());
    sf::FloatRect blockRect(pos, size);
    if (!intersects(object))
        return;

    float playerTop = object->getPosition().y;                                                      
    float playerBottom = object->getPosition().y + object->getSize().y;                                          
    float blockTop = pos.y;                                                    
    float blockBottom = pos.y + size.y;                                     

    bool verticalOverlap = playerBottom > blockTop && playerTop < blockBottom;    
    if (!verticalOverlap)                                                         
        return;

    float playerLeft = object->getPosition().x;   
    float playerRight = object->getPosition().x + object->getSize().x; 
    float blockLeft = pos.x;
    float blockRight = pos.x + size.x;

    auto comp = object->getComponent<MovementsComponent>();
    
    sf::Vector2f newpos = object->getPosition();
    if (comp->VelocityX > 0) {
        newpos.x = blockLeft - object->getSize().x;
    }
    else if (comp->VelocityX < 0) {
        newpos.x = blockRight;
    }

    object->setPosition(newpos);
    comp->VelocityX = 0;
}

void Collider::collisionVert(Object* object) {
    sf::FloatRect playerRect(object->getPosition(),  object->getSize());
    sf::FloatRect blockRect(pos, size);
    if (!intersects(object))
        return;


    float playerLeft = object->getPosition().x;   
    float playerRight = object->getPosition().x + object->getSize().x; 
    float blockLeft = pos.x;
    float blockRight = pos.x + size.x;

    bool horizontalOverlap = playerRight > blockLeft && playerLeft < blockRight;
    if (!horizontalOverlap)
        return;

    float playerTop = object->getPosition().y;                                                      
    float playerBottom = object->getPosition().y + object->getSize().y;                                          
    float blockTop = pos.y;                                                    
    float blockBottom = pos.y + size.y;    

    auto comp = object->getComponent<MovementsComponent>();
    
    sf::Vector2f newpos = object->getPosition();
    if (comp->VelocityY < 0) {
        newpos.y = blockTop - object->getSize().y;
    }
    else if (comp->VelocityY > 0) {
        newpos.y = blockBottom;
    }
    
    object->setPosition(newpos);
    comp->VelocityY = 0;
}

void Collider::render() {
    GameEngine::getWindow()->draw(rect);
}
