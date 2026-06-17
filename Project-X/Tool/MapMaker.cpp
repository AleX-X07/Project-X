#include "MapMaker.h"

#include <map>

MapMaker::MapMaker(std::string _folder, sf::Vector2f _sizeImage) : folder(_folder), sizeImage(_sizeImage) {
    background = new Object(levelSize);
    
    std::filesystem::directory_iterator it{folder};
    
    for (auto& p : it) {
        if (p.path().extension() == ".png") {
            images.push_back(p.path());
        }
    }
}

MapMaker::~MapMaker() {
    
}

void MapMaker::makeBackground() {
    sf::RenderTexture renderTex(sf::Vector2u(levelSize));
    
    for (int X = 0; X < levelSize.x; X++) {
        for (int Y = 0; Y < levelSize.y; Y++) {
            sf::Texture texture;
            texture.loadFromFile();
            sf::Sprite
        }
    }
    
}

int MapMaker::randomInt(int min, int max) {

    int getRandomNumber(int min, int max)
    {
        std::random_device m_rd;
        std::mt19937 m_gen(m_rd());

        std::uniform_int_distribution<int> dis(min, max);
        return dis(m_gen);
    }
}

Object* MapMaker::getBackground() {
    return background;
}
