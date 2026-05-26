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
                    Object* newObj = new Object({currentObj["Position"][0],currentObj["Position"][1]},{currentObj["Size"][0],currentObj["Size"][1]});
                    addScene->addObject(newObj, currentObj["LayerPosition"]);
                }
            }
        }
    }
}

void SceneReader::SceneTestDev() {
    Scene* addScene = new Scene(2);
    GameEngine::getVecState().push_back(addScene);
<<<<<<< Updated upstream
    
    Object* newObj = new Object({0, 0}, { 50, 50});
    
    newObj->addComponent(new InputComponent(newObj));
    newObj->addComponent(new RenderComponent(newObj, "Sprite/Debug/Baker.png"));
    newObj->addComponent(new movementsComponent(newObj, 500));
=======
>>>>>>> Stashed changes
    
    addScene->addObject(newObj, 1);
}
