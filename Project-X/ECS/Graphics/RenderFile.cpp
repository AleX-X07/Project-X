#include "RenderFile.h"
#include "../../Main/GameEngine.h"

RenderFile::RenderFile(Object* _owner) : Component(_owner) {
    texture = new sf::Texture();
    rect = new sf::RectangleShape(owner->getSize());
    rect->setPosition(owner->getPosition());
    currentAnimation = nullptr;
}

RenderFile::RenderFile(Object* _owner, std::string name) : Component(_owner)
{
    texture = new sf::Texture();
    rect = new sf::RectangleShape(owner->getSize());
    rect->setPosition(owner->getPosition());
    if (texture->loadFromFile(name)) {
        rect->setTexture(texture);
    }
    currentAnimation = nullptr;
}

RenderFile::~RenderFile() {
    delete texture;
    texture = nullptr;
    
    delete rect;
    rect = nullptr;
}

void RenderFile::update(float deltaTime) {
    rect->setPosition(owner->getPosition());
    if (currentAnimation != nullptr) {
        currentAnimation->update(deltaTime);
    }
}

void RenderFile::render() {
    if (texture == nullptr) {
        rect->setFillColor(sf::Color::Red);
    }
    GameEngine::getWindow()->draw(*rect);
}

void RenderFile::setTexture(std::string newPath) {
    if (texture->loadFromFile(newPath)) {
        rect->setTexture(texture);
        sf::Vector2u texSize = texture->getSize();
        rect->setTextureRect(sf::IntRect({0, 0}, {sf::Vector2i(texSize)}));
        currentAnimation = nullptr; 
    }
}

void RenderFile::setTexture(sf::Texture* newTexture) {
    texture = newTexture;
    rect->setTexture(texture);
}

void RenderFile::setAnimation(Animation* animation) {
    if (currentAnimation == animation) {
        return;
    }
    currentAnimation = animation;
}

sf::RectangleShape* RenderFile::getRect() {
    return rect;
}

sf::Texture* RenderFile::getTexture() {
    return texture;
}
