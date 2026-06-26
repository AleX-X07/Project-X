#pragma once
#include "../Component.h"
#include "../../Tool/MapMaker.h"

class MapMakeComponent : public Component {
private:
    MapMaker* myMaker;
    
public:
    MapMakeComponent(Object* _owner, std::string folder, sf::Vector2f sizeImage);
    virtual ~MapMakeComponent() override;
    
    MapMaker* getMaker();
    virtual void render() override;
};
