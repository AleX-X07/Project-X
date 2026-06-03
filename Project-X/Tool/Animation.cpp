#include "Animation.h"

#include <iostream>

#include "../ECS/Object.h"
#include "../ECS/Graphics/RenderComponent.h"

Animation::Animation(Object* _owner, nlohmann::basic_json<> _myAnimation) : myAnimation(_myAnimation) {
    owner = _owner;
    
    texture = new sf::Texture();
    if (!texture->loadFromFile(_myAnimation.back())) {
        std::cerr << "Error loading texture from file" << "\n";
    }
    
    nlohmann::basic_json<> value = _myAnimation[0]["args"];
    
    sizeSpriteSheet = {value[0], value[1]};
    nbrFrames = value[2];
    frameRate = value[3];
}

sf::Texture* Animation::getTexture() {
    return texture;
}

void Animation::update(float deltaTime) {
    startPoint += deltaTime;
    
    if (startPoint >= frameRate) {
        locTexture.x = sizeSpriteSheet.x / frameRate * actualFrame;
        offset = sf::IntRect({locTexture.x, 0}, {sizeSpriteSheet.x, sizeSpriteSheet.y});
        if (owner->hasComponent<RenderComponent>()) {
            owner->getComponent<RenderComponent>()->getRect()->setTextureRect(offset);
        }
        actualFrame++;
        startPoint = 0;
    }
    
    if (actualFrame == nbrFrames) {
        actualFrame = 0;
        locTexture = {0,0};
    }
}

void Animation::render() {
    owner->getComponent<RenderComponent>()->setAnimation(this);
}
