#include "MapMaker.h"

#include <map>

#include "../ECS/Graphics/RenderFile.h"

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
    renderTex = sf::RenderTexture(sf::Vector2u(levelSize));
    
    float tilesX = levelSize.x / sizeImage.x;
    float tilesY = levelSize.y / sizeImage.y;
    
    for (int X = 0; X < tilesX; X++) {
        for (int Y = 0; Y < tilesY; Y++) {
            sf::Texture texture;
            int nbr = Random::getInstance()->getRandomInt(0,images.size()-1);
            texture.loadFromFile(images[nbr].c_str());
            sf::Sprite sprite(texture);
            sprite.setPosition({X*sizeImage.x,Y*sizeImage.y});
            renderTex.draw(sprite);
        }
    }
    renderTex.display();
}

Object* MapMaker::getBackground() {
    if (!background->hasComponent<RenderFile>()) {
        background->addComponent(new RenderFile(background));
        background->getComponent<RenderFile>()->setTexture(new sf::Texture(renderTex.getTexture()));
    }
    return background;
}
