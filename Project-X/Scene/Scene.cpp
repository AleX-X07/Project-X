#include "Scene.h"
#include "../Main/GameEngine.h"
#include "../ECS/Tool/HealthComponent.h"
#include "../Reader/SceneReader.h"
#include "../ECS/Object.h"

Scene::Scene() : Scene(0){
}

Scene::Scene(int _idScene) : idScene(_idScene), state(State::Run), objectsScreen(nullptr)  {
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

std::vector<std::string>& Scene::getScreenVec() {
    return screenVec;
}

std::vector<Object*>* Scene::getObjectsScreen() {
    return objectsScreen;
}

std::vector<std::vector<Object*>*>& Scene::getPreviousScreen() {
    return previousScreen;
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

void Scene::setObjectsScreen(std::vector<Object*>* _objectsScreen) {
    objectsScreen = _objectsScreen;
}

void Scene::setIdScene(int _idScene) {
    idScene = _idScene;
}

void Scene::setState(State newState) {
    state = newState;
}

void Scene::setScreen(std::string newScreen) {
    screen = newScreen;
    objectsScreen = SceneReader::getInstance()->initScreen(screen,this);
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
    if (objectsScreen != nullptr) {
        if (!objectsScreen->empty()) {
            for (auto& objScreen : *objectsScreen) {
                objScreen->update(deltatime);
            }
        }
    }
}

void Scene::render() {
    myLayer.render();
    if (objectsScreen != nullptr) {
        if (!objectsScreen->empty()) {
            GameEngine::getWindow()->setView(GameEngine::getWindow()->getDefaultView());
            for (auto& objScreen : *objectsScreen) {
                objScreen->render();
            }
            for (auto& obj : myObjects) {
                auto cam = obj->getComponent<CameraComponent>();
                if (cam != nullptr) {
                    GameEngine::getWindow()->setView(*cam->view);
                }
            }
        }
    }
}