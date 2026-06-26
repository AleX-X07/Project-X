#include "MapMakeComponent.h"

MapMakeComponent::MapMakeComponent(Object* _owner, std::string folder, sf::Vector2f sizeImage) : Component(_owner) {
    myMaker = new MapMaker(folder, sizeImage);
    myMaker->makeBackground();
}

MapMakeComponent::~MapMakeComponent() {
    delete myMaker;
    myMaker = nullptr;
}

MapMaker* MapMakeComponent::getMaker() {
    return myMaker;
}

void MapMakeComponent::render() {
    myMaker->getBackground()->render();
}
