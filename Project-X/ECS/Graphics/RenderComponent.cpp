#include "RenderComponent.h"
#include "../../Main/GameEngine.h"

RenderComponent::RenderComponent(Object* _owner, std::string name) : Component(_owner)
{
    texture = new sf::Texture();
    rect = new sf::RectangleShape(owner->getSize());
    rect->setPosition(owner->getPosition());
    if (texture->loadFromFile(name)) {
        rect->setTexture(texture);
    }
}

RenderComponent::~RenderComponent() {
    delete texture;
    texture = nullptr;
    
    delete rect;
    rect = nullptr;
}

void RenderComponent::update(float deltaTime) {
    rect->setPosition(owner->getPosition());
}

void RenderComponent::render() {
    if (texture != nullptr) {
        GameEngine::getWindow()->draw(*rect);
    }
}

void RenderComponent::setAnimation(Animation* animation) {
    if (currentAnimation == animation) {
        return;
    }
    currentAnimation = animation;
    rect->setTexture(animation->texture, true);
}
