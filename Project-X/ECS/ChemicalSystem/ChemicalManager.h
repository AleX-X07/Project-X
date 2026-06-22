#pragma once
#include "../Object.h"
#include "ElementMain.h"

class ChemicalManager : public Component {
public:
    std::vector<ElementMain*> List;
    std::vector<Object*> rectlist;
    
public:
    ChemicalManager(Object* owner);
    ~ChemicalManager();
    
    void update(float deltaTime) override;
    void render() override;
    
    void addState(ElementMain* Element);
};
