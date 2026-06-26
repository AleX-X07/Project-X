#include "ChemicalRenderer.h"

#include "ChemicalManager.h"
#include "../../Main/GameEngine.h"
#include "State/CH_Fire.h"
#include "State/CH_Ice.h"
#include "State/CH_Lightning.h"
#include "State/CH_Poison.h"

ChemicalRenderer::ChemicalRenderer(Object* owner) : Component(owner) {
    pos.x = owner->getPosition().x;
    pos.y = owner->getPosition().y + owner->getSize().y + 5;

    size = {10, 10};
    offset = (owner->getSize().x - 40) / 4;
    
    for (int z = 0; z < 4; z++) {
        Object* rect = new Object({pos.x + (z * (offset + size.x)), pos.y}, size);
        rect->addComponent(new RenderFile(rect, "Assets/EffectIcon/Icon_" + std::to_string(z+1) + ".png" ) );
        
        rectlist.push_back(rect);
    }
}

ChemicalRenderer::~ChemicalRenderer() {
    for (auto c : rectlist) {
        delete c;
        c = nullptr;
    }
}

void ChemicalRenderer::update(float deltaTime) {
    int b = 0;
    
    pos.x = owner->getPosition().x;
    pos.y = owner->getPosition().y + owner->getSize().y + 5;
    
    for (auto z : rectlist) {
        z->setPosition({pos.x + (b * offset), pos.y});
        auto comp = z->getComponent<RenderFile>();
        comp->getRect()->setPosition({pos.x + (b * (offset + size.x)), pos.y});
        
        b++;
    }
}

void ChemicalRenderer::render() {
    auto chem = owner->getComponent<ChemicalManager>();
    
    bool hasFire = false;
    bool hasIce = false;
    bool hasLightning = false;
    bool hasPoison = false;
    
    if (chem) {
        for (auto x : chem->List) {
            if (dynamic_cast<CH_Fire*>(x)) hasFire = true;
            else if (dynamic_cast<CH_Ice*>(x)) hasIce = true;
            else if (dynamic_cast<CH_Lightning*>(x)) hasLightning = true;
            else if (dynamic_cast<CH_Poison*>(x)) hasPoison = true;
        }
    }
    
    bool states[4] = { hasFire, hasIce, hasLightning, hasPoison };
    
    for (size_t i = 0; i < rectlist.size(); i++) {
        if (states[i]) {
            rectlist[i]->render();
        }
    }
}