#include "Scene.h"

Scene::Scene(int nbrLayer) {
    myLayer.setNbrLayer(nbrLayer);
}

Layer& Scene::getMyLayer() {
    return myLayer;
}

std::vector<Object*>& Scene::getVecObjects() {
    return myObjects;
}

void Scene::addObject(Object* addObject, int Layer) {
    myObjects.push_back(addObject);
    getMyLayer().addInLayer(addObject, Layer);
}

void Scene::update(float deltatime) {
    for (auto& obj : myObjects) {
        obj->update(deltatime);
    }
}

void Scene::render() {
    for (auto& obj : myObjects) {
        obj->render();
    }
}
