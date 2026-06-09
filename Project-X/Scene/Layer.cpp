#include "Layer.h"

#include "../Main/GameEngine.h"

Layer::Layer() {
    nbrLayers = 1;
}

void Layer::setNbrLayer(int _nbrLayers) {
    nbrLayers = _nbrLayers;
    for (int X = 0; X < nbrLayers; X++) {
        std::vector<Object*> newLayer;
        layers.push_back(newLayer);
    }
}

void Layer::addInLayer(Object* myObject, int layer) {
    if (layer < nbrLayers ) {
        layers[layer].push_back(myObject);
    }
    else {
        std::cerr << "Layer out of bounds" << std::endl;
    }
}

void Layer::addInHUD(Object* myObject) {
    HUD.push_back(myObject);
}

void Layer::render() {
    for (auto& layer : layers) {
        for (auto& object : layer) {
            object->render();
        }
    }
    GameEngine::getWindow()->setView(GameEngine::getWindow()->getDefaultView());
    for (auto& H : HUD) {
        H->render();
    }
}
