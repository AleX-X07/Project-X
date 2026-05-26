#include "Scene.h"

Scene::Scene(int nbrLayer) {
    myLayer.setNbrLayer(nbrLayer);
}

Layer& Scene::getMyLayer() {
    return myLayer;
}

std::vector<GameObject*>& Scene::getVecObjects() {
    return myObjects;
}

void Scene::update(float deltatime) {
    for (auto& obj : myObjects) {
        obj->update();
    }
}

void Scene::render() {
    for (auto& obj : myObjects) {
        obj->render();
    }
}
