#pragma once

#include "../Object.h"
#include "ElementMain.h"

class ChemicalRenderer : public Component {
public:
    std::vector<Object*> rectlist;
    
    sf::Vector2f pos;
    sf::Vector2f size;
    
    float offset;
    
public:
    ChemicalRenderer(Object* owner);
    ~ChemicalRenderer();
    
    void update(float deltaTime) override;
    void render() override;
};
