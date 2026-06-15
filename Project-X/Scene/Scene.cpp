#include "Scene.h"
#include "../Main/GameEngine.h"
#include "../ECS/Tool/HealthComponent.h"
#include "../Reader/SceneReader.h"

Scene::Scene() : Scene(0){
}

Scene::Scene(int _idScene) : idScene(_idScene), state(State::Run)  {
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

int& Scene::getIdScene() {
    return idScene;
}

Scene::State& Scene::getState() {
    return state;
}

void Scene::addObject(Object* addObject, int Layer) {
    myObjects.push_back(addObject);
    getMyLayer().addInLayer(addObject, Layer);
}

void Scene::setIdScene(int _idScene) {
    idScene = _idScene;
}

void Scene::setState(State newState) {
    state = newState;
}

void Scene::setScreen(std::string newScreen) {
    screen = newScreen;
}

void Scene::setLayer(int Layer) {
    myLayer.setNbrLayer(Layer);
}

void Scene::update(float deltatime) {
    if (state == State::Run) {
        for (auto& obj : myObjects) {
            obj->update(deltatime);
        }
    }
    for (auto& objScreen : SceneReader::getScreen()[screen]) {
        objScreen->update(deltatime);
    }
    
}

void Scene::render() {
    myLayer.render();
    GameEngine::getWindow()->setView(GameEngine::getWindow()->getDefaultView());
    for (auto& objScreen : SceneReader::getScreen()[screen]) {
        objScreen->render();
    }
    for (auto& obj : myObjects) {
        auto cam = obj->getComponent<CameraComponent>();
        if (cam != nullptr) {
            GameEngine::getWindow()->setView(*cam->view);
        }
    }
}