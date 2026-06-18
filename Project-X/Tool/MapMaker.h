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
    
    std::vector<Object*> itemMap;
    
public:
    MapMaker(std::string _folder, sf::Vector2f _sizeImage);
    ~MapMaker();
    
    std::vector<Object*>& getItemMap();
    
    void makeBackground();
    void addItemOnMap();
    
    Object* getBackground();
};
