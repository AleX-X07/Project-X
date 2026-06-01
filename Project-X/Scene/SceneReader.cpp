#include "SceneReader.h"

#include "../ECS/Box/HurtBox.h"
#include "../Main/GameEngine.h"

std::unordered_map <
    std::string,
    ComponentFactory
> SceneReader::factories = {
    {"Render",   [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new RenderComponent(obj, ecs["args"][0]);
    }},
    {"Mouse",    [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new MouseComponent(obj);
    }},
    {"Input",    [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new InputComponent(obj);
    }},
    {"Movement", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new movementsComponent(obj, ecs["args"][0]);
    }},
    {"HurtBox", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new HurtBox(obj, {ecs["args"][0],ecs["args"][1]}, currentScene->getVecObjects());
    }},
    {"HitBox", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new HitBox(obj, {ecs["args"][0],ecs["args"][1]});
    }},
    {"BulletManager", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new BulletManager(obj);
    }},
    {"BulletSystemComponent", [](Object* obj, const nlohmann::json& ecs, Scene* currentScene) -> Component* {
        return new BulletSystemComponent(obj, ecs["args"][0], ecs["args"][1], ecs["args"][2], ecs["args"][3]);
    }},
};

void SceneReader::loadScene() {
    std::ifstream scene("Data/Scene.json");
    if (scene.is_open()) {
        nlohmann::json data = nlohmann::json::parse(scene);
        
        for (auto& sceneData : data["Scene"]) {
            
            std::string myScene = sceneData.get<std::string>() + ".json";
            std::string path = "Data/Scene/" + myScene;
            std::ifstream currentScene(path);
            
            if (currentScene.is_open()) {
                nlohmann::json data2 = nlohmann::json::parse(currentScene);
                
                Scene* addScene = new Scene(data2["ID"]);
                GameEngine::getVecState().push_back(addScene);
                addScene->setLayer(data2["Layer"]);
                nlohmann::json objects = data2["Objects"];
                
                for (auto& currentObj : objects) {
                    Object* newObj = new Object({currentObj["Position"][0],currentObj["Position"][1]},{currentObj["Size"][0],currentObj["Size"][1]});
                    
                    if (currentObj["Type"]["TypeName"] == "Transition") {
                        std::string currentTransitionType = currentObj["Type"]["Transition"][1];
                        Transition::TransitionType transitionType;
                        if (currentTransitionType == "Click") {
                            transitionType = Transition::TransitionType::Button;
                        }
                        Transition* newTrans = new Transition(currentObj["Type"]["Transition"][0], transitionType ,newObj);
                        addScene->addTransition(newTrans);
                    }
                    
                    for (auto& ecs : currentObj["ECS"]) {
                        std::string name = ecs["Component"];
                        
                        if (factories.count(name)) {
                            newObj->addComponent(factories[name](newObj, ecs, addScene));
                        } else {
                            std::cerr << "Composant inconnu : " << name << std::endl;
                        }
                    }
                    addScene->addObject(newObj, currentObj["LayerPosition"]);
                }
            }
        }
    }
    for (auto& vS : GameEngine::getVecState()) {
        for (auto& vS2 : GameEngine::getVecState()) {
            if (vS != vS2 && vS->getIdScene() == vS2->getIdScene()) {
                std::cout << "Id déjà existant" << std::endl;
                abort();
            }
        }
    }
}

void SceneReader::SceneTestDev() {
    Scene* addScene = new Scene(2);
    addScene->setLayer(2);
    GameEngine::getVecState().push_back(addScene);
    
    Object* newObj = new Object({0, 0}, { 50, 50});
    Object* Hurt = new Object({0, 0}, { 50, 50});
    
    newObj->addComponent(new InputComponent(newObj));
    newObj->addComponent(new RenderComponent(newObj, "Assets/Debug/Baker.png"));
    newObj->addComponent(new MouseComponent(newObj));
    newObj->addComponent(new movementsComponent(newObj, 500));
    newObj->addComponent(new BulletManager(newObj));
    newObj->addComponent(new HurtBox(newObj, {50, 50}, addScene->getVecObjects()));
    newObj->addComponent(new CameraComponent(newObj, 1920, 1080, 10000, 10000, false, 5));
    
    addScene->addObject(newObj, 1);
    
    Hurt->addComponent(new HurtBox(Hurt, {50, 50}, addScene->getVecObjects()));
    Hurt->addComponent(new RenderComponent(Hurt, "Assets/Debug/Collider_DebugTX.png"));
    Hurt->addComponent(new HealthComponent(Hurt, 1000));
    
    addScene->addObject(Hurt, 1);
}
