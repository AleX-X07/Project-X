#include "SceneReader.h"
#include "../Main/GameEngine.h"

std::unordered_map <
    std::string,
    ComponentFactory
> SceneReader::factories = {
    {"Render",   [](Object* obj, const nlohmann::json& ecs) -> Component* {
        return new RenderComponent(obj, ecs["args"][0]);
    }},
    {"Mouse",    [](Object* obj, const nlohmann::json& ecs) -> Component* {
        return new MouseComponent(obj);
    }},
    {"Input",    [](Object* obj, const nlohmann::json& ecs) -> Component* {
        return new InputComponent(obj);
    }},
    {"Movement", [](Object* obj, const nlohmann::json& ecs) -> Component* {
        return new movementsComponent(obj, ecs["args"][0]);
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
                            newObj->addComponent(factories[name](newObj, ecs));
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
    GameEngine::getVecState().push_back(addScene);
    
    Object* newObj = new Object({0, 0}, { 50, 50});
    
    newObj->addComponent(new InputComponent(newObj));
    newObj->addComponent(new RenderComponent(newObj, "Assets/Debug/Baker.png"));
    newObj->addComponent(new movementsComponent(newObj, 500));
    
    addScene->addObject(newObj, 1);
}
