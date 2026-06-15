#include "Animation.h"

#include <iostream>

#include "../ECS/Object.h"
#include "../ECS/Graphics/RenderFile.h"

Animation::Animation(Object* _owner, std::string texturePath, nlohmann::basic_json<> _myAnimation) : myAnimation(_myAnimation) {
    owner = _owner;
    
    texture = new sf::Texture();
    if (!texture->loadFromFile(texturePath)) {
        std::cerr << "Error loading texture from file" << "\n";
    }
    
    nlohmann::basic_json<> value = _myAnimation;
    
    sizeSpriteSheet = {value[0], value[1]};
    nbrFrames = value[2];
    frameRate = value[3];
    sizeSpriteSheet.x = sizeSpriteSheet.x / nbrFrames;
    
    actualFrame = 0;
    startPoint = 0;
    
    sf::IntRect offset({0, 0}, sizeSpriteSheet);
    if (owner->hasComponent<RenderFile>()) {
        owner->getComponent<RenderFile>()->getRect()->setTextureRect(offset);
    }
    
    textureSet = false;
}

sf::Texture* Animation::getTexture() {
    return texture;
}

void Animation::update(float deltaTime) {
    startPoint += deltaTime;
    
    if (startPoint >= frameRate) {
        startPoint = 0;

        locTexture.x = sizeSpriteSheet.x * actualFrame;
        offset = sf::IntRect({locTexture}, {sizeSpriteSheet});
        
        if (owner->hasComponent<RenderFile>()) {
            owner->getComponent<RenderFile>()->getRect()->setTextureRect(offset);
        }
        
        actualFrame++;
        if (actualFrame >= nbrFrames) {
            actualFrame = 0;
            locTexture = {0, 0};
        }
    }
    
    if (!textureSet) {
        if (owner->hasComponent<RenderFile>()) {
            owner->getComponent<RenderFile>()->setTexture(texture);
        }
        textureSet = true;
    }
}

void Animation::setAnimation() {
    owner->getComponent<RenderFile>()->setAnimation(this);
}
