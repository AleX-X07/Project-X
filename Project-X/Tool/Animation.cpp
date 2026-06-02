#include "Animation.h"
#include "../ECS/Object.h"
#include "../ECS/Graphics/RenderComponent.h"

Animation::Animation(Object* _owner, const char* path) {
    
    texture = new sf::Texture();
    texture->loadFromFile(path);
    
    owner = _owner;
}

void Animation::update(float deltaTime) {
    
}

void Animation::render() {
    owner->getComponent<RenderComponent>()->setAnimation(this);
}
