#include "Scene.h"

Scene::Scene(int _idScene) {
    idScene = _idScene;
}

Scene::~Scene() {
    for (auto& obj : myObjects) {
        delete obj;
        obj = nullptr;
    }
    myObjects.clear();
    for (auto& trans : myTransitions) {
        delete trans;
        trans = nullptr;
    }
    myTransitions.clear();
}

Layer& Scene::getMyLayer() {
    return myLayer;
}

std::vector<Object*>& Scene::getVecObjects() {
    return myObjects;
}

std::vector<Transition*>& Scene::getVecTransitions() {
    return myTransitions;
}

int Scene::getIdScene() {
    return idScene;
}

void Scene::addObject(Object* addObject, int Layer) {
    myObjects.push_back(addObject);
    getMyLayer().addInLayer(addObject, Layer);
}

void Scene::addTransition(Transition* addObject) {
    myTransitions.push_back(addObject);
}

void Scene::setLayer(int Layer) {
    myLayer.setNbrLayer(Layer);
}

void Scene::update(float deltatime) {
    for (auto& obj : myObjects) {
        obj->update(deltatime);
    }
    for (auto& trans : myTransitions) {
        trans->update();
    }
    //std::cout << idScene << std::endl;
}

void Scene::render() {
    for (auto& obj : myObjects) {
        obj->render();
    }
}
