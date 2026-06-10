#include "Scene.h"
#include "../Main/GameEngine.h"
#include "../ECS/Tool/HealthComponent.h"

Scene::Scene() {
}

Scene::Scene(int _idScene) {
    idScene = _idScene;
}

Scene::~Scene() {
    for (auto& obj : myObjects) {
        delete obj;
        obj = nullptr;
    }
    myObjects.clear();
}

Layer& Scene::getMyLayer() {
    return myLayer;
}

std::vector<Object*>& Scene::getVecObjects() {
    return myObjects;
}

int Scene::getIdScene() {
    return idScene;
}

void Scene::addObject(Object* addObject, int Layer) {
    myObjects.push_back(addObject);
    getMyLayer().addInLayer(addObject, Layer);
}

void Scene::setLayer(int Layer) {
    myLayer.setNbrLayer(Layer);
}

void Scene::setPaused(bool pause) {
    isPaused = pause;
}

void Scene::update(float deltatime) {
    if (isPaused) {
        return;
    }
    for (auto& obj : myObjects) {
        obj->update(deltatime);
    }
}

void Scene::render() {
    myLayer.render();
}