#pragma once

#include "../Object.h"
#include "../../Tool/Animation.h"

class GameEngine;

class RenderComponent final : public Component
{
private:
    sf::Texture* texture;
    sf::RectangleShape* rect;
    Animation* currentAnimation;

public:
    RenderComponent(Object* _owner);
    RenderComponent(Object* _owner, std::string name);
    ~RenderComponent() override;

    void update(float deltaTime) override;
    void render() override;
    
    void setTexture(std::string newPath);
    void setAnimation(Animation* animation);
    
    sf::RectangleShape* getRect();
};