#pragma once

#include "../Object.h"
#include "../../Tool/Animation.h"

class GameEngine;

class RenderFile final : public Component
{
private:
    sf::Texture* texture;
    sf::RectangleShape* rect;
    Animation* currentAnimation;

public:
    RenderFile(Object* _owner);
    RenderFile(Object* _owner, std::string name);
    ~RenderFile() override;

    void update(float deltaTime) override;
    void render() override;
    
    void setTexture(std::string newPath);
    void setTexture(sf::Texture* newTexture);
    void setAnimation(Animation* animation);
    
    sf::RectangleShape* getRect();
    sf::Texture* getTexture();
};