#pragma once
#include "SFML/Graphics.hpp"
#include <unordered_map>
#include <nlohmann/json.hpp>

class Object;

class Animation {
private:
    sf::Texture* texture;
    Object* owner;
    nlohmann::basic_json<>& myAnimation;
    
    sf::Vector2i sizeSpriteSheet;
    int nbrFrames;
    float frameRate;
    
    sf::Vector2i locTexture;
    int actualFrame;
    float startPoint;
    sf::IntRect offset;
    
    bool textureSet;
    
public:
    
    Animation(Object* _owner, std::string texturePath, nlohmann::basic_json<> _myAnimation);
    ~Animation() = default;
    
    sf::Texture* getTexture();
    
    void update(float deltaTime);
    void setAnimation();
};
