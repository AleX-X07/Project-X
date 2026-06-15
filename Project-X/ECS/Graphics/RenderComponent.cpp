#include "RenderComponent.h"
#include "../../Main/GameEngine.h"

RenderComponent::RenderComponent(Object* _owner) : Component(_owner) {
    texture = new sf::Texture();
    rect = new sf::RectangleShape(owner->getSize());
    rect->setPosition(owner->getPosition());
    currentAnimation = nullptr;
}

RenderComponent::RenderComponent(Object* _owner, std::string name) : Component(_owner)
{
    texture = new sf::Texture();
    rect = new sf::RectangleShape(owner->getSize());
    rect->setPosition(owner->getPosition());
    if (texture->loadFromFile(name)) {
        rect->setTexture(texture);
    }
    currentAnimation = nullptr;
}

RenderComponent::~RenderComponent() {
    delete texture;
    texture = nullptr;
    
    delete rect;
    rect = nullptr;
}

void RenderComponent::update(float deltaTime) {
    rect->setPosition(owner->getPosition());
    if (currentAnimation != nullptr) {
        currentAnimation->update(deltaTime);
    }
}

void RenderComponent::render() {
    if (texture == nullptr) {
        rect->setFillColor(sf::Color::Red);
    }
    GameEngine::getWindow()->draw(*rect);
}

void RenderComponent::setTexture(std::string newPath) {
    if (texture->loadFromFile(newPath)) {
        rect->setTexture(texture);
        sf::Vector2u texSize = texture->getSize();
        rect->setTextureRect(sf::IntRect({0, 0}, {sf::Vector2i(texSize)}));
        currentAnimation = nullptr; 
    }
}

void RenderComponent::setTexture(sf::Texture* newTexture) {
    texture = newTexture;
    rect->setTexture(texture);
}

void RenderComponent::setAnimation(Animation* animation) {
    if (currentAnimation == animation) {
        return;
    }
    currentAnimation = animation;
}

sf::RectangleShape* RenderComponent::getRect() {
    return rect;
}

sf::Texture* RenderComponent::getTexture() {
    return texture;
}
