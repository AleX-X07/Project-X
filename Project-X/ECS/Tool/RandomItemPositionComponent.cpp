#include "RandomItemPositionComponent.h"

#include "../Object.h"

RandomItemPositionComponent::RandomItemPositionComponent(Object* _owner, sf::Vector2i _posX, sf::Vector2i _posY) : Component(_owner) {
    limite = {levelSize.x - owner->getSize().x , levelSize.y - owner->getSize().y};
    _posX.y = _posX.y - owner->getSize().x;
    _posY.y = _posY.y - owner->getSize().y;
    if (_posX.x < 0 || _posY.x < 0 || _posX.y > limite.x || _posY.y > limite.y) {
        return;
    }
    
    owner->setPosition({static_cast<float>(Random::getInstance()->getRandomInt(_posX.x, _posX.y)),static_cast<float>(Random::getInstance()->getRandomInt(_posY.x, _posY.y))});
}
