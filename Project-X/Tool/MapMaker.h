#pragma once
#include <iostream>
#include <random>
#include "../ECS/Object.h"
#include "Globals.h"

class MapMaker {
private:
    std::string folder;
    Object* background;
    std::vector<std::filesystem::path> images;
    sf::Vector2f sizeImage;
    
public:
    MapMaker(std::string _folder, sf::Vector2f _sizeImage);
    ~MapMaker();
    
    void makeBackground();
    
    int randomInt(int min, int max);
    Object* getBackground();
};
