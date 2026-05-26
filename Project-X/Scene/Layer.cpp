#include "Layer.h"

void Layer::setNbrLayer(int _nbrLayers) {
    nbrLayers = _nbrLayers;
}

void Layer::addInLayer(Object* myObject, int layer) {
    if (layer < nbrLayers ) {
        layers[layer].push_back(myObject);
    }
    else {
        std::cerr << "Layer out of bounds" << std::endl;
    }
}

void Layer::render() {
    for (auto& layer : layers) {
        for (auto& object : layer) {
            object->render();
        }
    }
}
