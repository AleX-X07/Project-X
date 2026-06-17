#include "RenderAngle.h"
#include "../../Main/GameEngine.h"

RenderAngle::RenderAngle(Object* _owner) : Component(_owner) {
    texture = new sf::Texture();
    rect = new sf::RectangleShape(owner->getSize());
    rect->setPosition(owner->getPosition());
    currentAnimation = nullptr;
}

RenderAngle::RenderAngle(Object* _owner, std::string name, float angle) : Component(_owner)
{
    texture = new sf::Texture();
    rect = new sf::RectangleShape(owner->getSize());
    rect->setPosition(owner->getPosition());
    sf::Vector2f size = owner->getSize();
    rect->setOrigin({size.x / 2.f, size.y / 2.f});
    
    if (texture->loadFromFile(name)) {
        rect->setTexture(texture);
    }
    
    rect->setRotation(sf::degrees(angle));

    
}

RenderAngle::~RenderAngle() {
    delete texture;
    texture = nullptr;
    
    delete rect;
    rect = nullptr;
}

void RenderAngle::update(float deltaTime) {
    rect->setPosition(owner->getPosition());
    if (currentAnimation != nullptr) {
        currentAnimation->update(deltaTime);
    }
}

void RenderAngle::render() {
    if (texture == nullptr) {
        rect->setFillColor(sf::Color::Red);
    }
    GameEngine::getWindow()->draw(*rect);
}

void RenderAngle::setTexture(std::string newPath) {
    if (texture->loadFromFile(newPath)) {
        rect->setTexture(texture);
        sf::Vector2u texSize = texture->getSize();
        rect->setTextureRect(sf::IntRect({0, 0}, {sf::Vector2i(texSize)}));
        currentAnimation = nullptr; 
    }
}

void RenderAngle::setTexture(sf::Texture* newTexture) {
    texture = newTexture;
    rect->setTexture(texture);
}

void RenderAngle::setAnimation(Animation* animation) {
    if (currentAnimation == animation) {
        return;
    }
    currentAnimation = animation;
}

sf::RectangleShape* RenderAngle::getRect() {
    return rect;
}

sf::Texture* RenderAngle::getTexture() {
    return texture;
}
