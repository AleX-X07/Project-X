#pragma once
#include "../Object.h"
#include "ElementMain.h"

class ChemicalManager : public Component {
public:
    std::vector<ElementMain*> List;
    
public:
    ChemicalManager(Object* owner);
    ~ChemicalManager();
    
    void update(float deltaTime) override;
    
    void addState(ElementMain* Element);
};
