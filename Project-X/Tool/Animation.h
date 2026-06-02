#pragma once
#include "../ECS/Graphics/RenderComponent.h"

class Animation {
private:
    sf::Texture* texture;
    
public:
    
    Animation(const char* path);
    ~Animation();
    
    void update(float deltaTime);
    void render(RenderComponent& renderOwner);
};
