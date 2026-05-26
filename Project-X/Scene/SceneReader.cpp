#include "SceneReader.h"
#include "../Main/GameEngine.h"

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
                
                Scene* addScene = new Scene(data2["Layer"]);
                
                nlohmann::json objects = data2["Objects"];
                
                for (auto& currentObj : objects) {
                    std::cout << currentObj["test"] << std::endl;
                }
            }
        }
    }
}

void SceneReader::SceneTestDev() {
    Scene* addScene = new Scene(2);
    
    Object* newObj = new Object();
    addScene->addObject(newObj, 0);
    
    
}
