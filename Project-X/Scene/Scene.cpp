#include "Scene.h"

Scene::Scene(int _idScene) {
    idScene = _idScene;
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

void Scene::setLayer(int Layer) {
    myLayer.setNbrLayer(Layer);
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
