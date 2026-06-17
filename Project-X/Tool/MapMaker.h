#pragma once
#include <iostream>
#include <random>
#include "../ECS/Object.h"
#include "Globals.h"
#include "Random.h"

class MapMaker {
private:
    std::string folder;
    Object* background;
    std::vector<std::filesystem::path> images;
    sf::Vector2f sizeImage;
    sf::RenderTexture renderTex;
    
public:
    MapMaker(std::string _folder, sf::Vector2f _sizeImage);
    ~MapMaker();
    
    void makeBackground();
    
    Object* getBackground();
};
