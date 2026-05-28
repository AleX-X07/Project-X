#include "SceneReader.h"

#include "../ECS/HurtBox.h"
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
    GameEngine::getVecState().push_back(addScene);
    
    Object* newObj = new Object({0, 0}, { 50, 50});
    Object* Hurt = new Object({0, 0}, { 50, 50});
    
    
    newObj->addComponent(new InputComponent(newObj));
    newObj->addComponent(new MouseComponent(newObj));
    newObj->addComponent(new RenderComponent(newObj, "Sprite/Debug/Baker.png"));
    newObj->addComponent(new movementsComponent(newObj, 500));
    newObj->addComponent(new BulletManager(newObj));
    addScene->addObject(newObj, 1);
    
    Hurt->addComponent(new HurtBox(Hurt, 1, {50, 50}, addScene->getVecObjects()));
    Hurt->addComponent(new RenderComponent(Hurt, "Sprite/Debug/Collider_DebugTX.png"));
    
    addScene->addObject(Hurt, 1);
}
