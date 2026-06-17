#include "RandomItemPositionComponent.h"

#include "../Object.h"

RandomItemPositionComponent::RandomItemPositionComponent(Object* _owner, sf::Vector2i _posX, sf::Vector2i _posY) : Component(_owner) {
    if (_posX.x < 0 || _posY.x < 0 || _posX.y > levelSize.x - owner->getSize().x || _posY.y > levelSize.y - owner->getSize().y) {
        return;
    }
    owner->setPosition({static_cast<float>(Random::getInstance()->getRandomInt(_posX.x, _posX.y)),static_cast<float>(Random::getInstance()->getRandomInt(_posY.x, _posY.y))});
}
