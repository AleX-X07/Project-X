#include "SceneReader.h"

#include "../ECS/Tool/TimerComponent.h"
#include "../Main/GameEngine.h"

std::unordered_map<std::string, Scene*> SceneReader::scenesHUD;

void SceneReader::read() {
    std::ifstream scene("Data/Scene/SceneManager.json");
    if (scene.is_open()) {
        nlohmann::json data = nlohmann::json::parse(scene);
        
        for (auto& sceneData : data["Scene"]) {
            
            std::string myScene = sceneData.get<std::string>() + ".json";
            std::string path = "Data/Scene/Scene/" + myScene;
            std::ifstream currentScene(path);
            
            if (currentScene.is_open()) {
                nlohmann::json data2 = nlohmann::json::parse(currentScene);
                
                Scene* addScene = new Scene(data2["ID"]);
                GameEngine::getVecState().push_back(addScene);
                addScene->setLayer(data2["Layer"]);
                nlohmann::json objects = data2["Objects"];
                
                for (auto& currentObj : objects) {
                    Object* newObj = new Object({currentObj["Position"][0],currentObj["Position"][1]},{currentObj["Size"][0],currentObj["Size"][1]});
                    
                    if (currentObj["Team"] == "Player") {
                        newObj->team = Object::Team::Player;
                    }
                    else if (currentObj["Team"] == "Enemy") {
                        newObj->team = Object::Team::Enemy;
                    }
                    else {
                        newObj->team = Object::Team::Neutral;
                    }
                    
                    for (auto& ecs : currentObj["ECS"]) {
                        std::string name = ecs["Component"];
                        
                        if (FactoriesECS::factories.count(name)) {
                            newObj->addComponent(FactoriesECS::factories[name](newObj, ecs, addScene));
                        } else {
                            std::cerr << "Composant inconnu : " << name << std::endl;
                        }
                        if (name == "StateMachine") {
                            readAnimation(ecs, newObj);
                        }
                        if (name == "HUD") {
                            readHUD(ecs, newObj, addScene);
                        }
                    }
                    addScene->addObject(newObj, currentObj["LayerPosition"]);
                }
            }
        }
    }
    
    std::ifstream sceneHUD("Data/Scene/SceneManagerHUD.json");
    if (sceneHUD.is_open()) {
        nlohmann::json data = nlohmann::json::parse(sceneHUD);
        
        for (auto& sceneData : data["Manager"]) {
            readSceneHUD(sceneData);
        }
    }
    
    for (auto& vS : GameEngine::getVecState()) {
        for (auto& vS2 : GameEngine::getVecState()) {
            if (vS != vS2 && vS->getIdScene() == vS2->getIdScene()) {
                std::cout << "Id déjà existant" << std::endl;
            }
        }
    }
}

void SceneReader::readAnimation(nlohmann::basic_json<>& ecs, Object* newObj) {
    std::string fileName = ecs["args"][0].get<std::string>() + ".json";
    std::string path = "Data/Animation/" + fileName;
    std::ifstream pathA(path);
    
    nlohmann::json dataA = nlohmann::json::parse(pathA);
    
    std::unordered_map<std::string, nlohmann::basic_json<>>* myMap = new std::unordered_map<std::string, nlohmann::basic_json<>>();
    std::unordered_map<std::string, State*>* mapState = new std::unordered_map<std::string, State*>();
    
    nlohmann::json dataFirstState = dataA["FirstState"];
    nlohmann::json dataState = dataA["State"];
    
    for (auto& [stateName, stateData] : dataState.items()) {
        (*myMap)[stateName] = stateData;
    }
    newObj->getComponent<StateMachineComponent>()->setSM(myMap,mapState,dataFirstState);
}

void SceneReader::readSceneHUD(std::string file) {
    std::string fileName = file + ".json";
    std::string path = "Data/Scene/SceneHUD/" + fileName;
    std::ifstream currentScene(path);
    
    nlohmann::json data = nlohmann::json::parse(currentScene);
    
    Scene* newScene = new Scene();
    newScene->setLayer(data["Layer"]);
    
    for (auto& currentObj : data["Objects"]) {
        Object* newObj = new Object({currentObj["Position"][0],currentObj["Position"][1]},{currentObj["Size"][0],currentObj["Size"][1]});
        
        for (auto& ecs : currentObj["ECS"]) {
            std::string name = ecs["Component"];
            
            if (FactoriesECS::factories.count(name)) {
                newObj->addComponent(FactoriesECS::factories[name](newObj, ecs, newScene));
            } else {
                std::cerr << "Composant inconnu : " << name << std::endl;
            }
            if (name == "StateMachine") {
                readAnimation(ecs, newObj);
            }
        }
        newScene->addObject(newObj, currentObj["LayerPosition"]);
    }
    scenesHUD[file] = newScene;
}

void SceneReader::readHUD(nlohmann::basic_json<>& ecs, Object* newObj, Scene* newScene) {
    auto hud = newObj->getComponent<HUD>();
    
    if (hud != nullptr) {
        for (auto& item : ecs["args"]) {
            for (auto& [key, value] : item.items()) {
                std::string name = key + "Display";
                if (FactoriesECS::factories.count(name)) {
                    hud->addHUD(FactoriesECS::factories[name](newObj, value, newScene));
                }
            }
        }
    }
}

void SceneReader::SceneTestDev() {
    Scene* addScene = new Scene(2);
    addScene->setLayer(2);
    GameEngine::getVecState().push_back(addScene);
    
    // DebugMap for dev only
    Object* Map = new Object({0, 0}, { 1920*2, 1080*2});
    Map->addComponent(new RenderFile(Map, "Assets/Debug/map.png"));
    addScene->addObject(Map, 1);
    // End Debug
    
    Object* newObj = new Object({200, 200}, { 50, 50});
    Object* Hurt = new Object({0, 0}, { 50, 50});
    Object* Exp = new Object({0, 0}, { 50, 50});
    
    Hurt->addComponent(new AiMobSpawner(Hurt, addScene->getVecObjects()));

    newObj->team = Object::Team::Player;

    newObj->addComponent(new InputComponent(newObj));
    newObj->addComponent(new RenderFile(newObj, "Assets/Character/hero1.png"));
    newObj->addComponent(new MouseComponent(newObj));
    newObj->addComponent(new MovementsComponent(newObj, 500));
    newObj->addComponent(new BulletManager(newObj));
    newObj->addComponent(new WeaponMain(newObj, "Deagle"));
    newObj->addComponent(new HurtBox(newObj, {50, 50}, addScene->getVecObjects(), 1));
    newObj->addComponent(new CameraComponent(newObj, false, 5));
    newObj->addComponent(new HealthComponent(newObj, 1000, addScene->getVecObjects()));
    newObj->addComponent(new ExpManager(newObj));
    //newObj->addComponent(new DebugHudComp(newObj));
    newObj->addComponent(new CrossHairComponent(newObj));
    newObj->addComponent(new TimerComponent(newObj,60));
    newObj->addComponent(new HUD(newObj));
    newObj->getComponent<HUD>()->addHUD(new HealthDisplay(newObj,{0, 0}, 24, sf::Color::White, "Assets/Font/Brown Cookies.otf"));
    newObj->getComponent<HUD>()->addHUD(new TimerDisplay(newObj,{WindowSize.x/2,0},24,sf::Color::White, "Assets/Font/Brown Cookies.otf"));
    
    Exp->addComponent(new ExpComponent(Exp, {50, 50}, addScene->getVecObjects(), 10));
    Exp->addComponent(new RenderFile(Exp, "Assets/Debug/ExpDebug.png"));
    
    newObj->addComponent(new ScreenManager(newObj, addScene));
    
    addScene->addObject(newObj, 1);
    addScene->addObject(Hurt, 1);
    addScene->addObject(Exp, 1);
}

void SceneReader::SceneTestDev2() {
    Scene* myScene = new Scene(0);
    myScene->setLayer(2);
    GameEngine::getVecState().push_back(myScene);
    
    Object* Hero = new Object({0, 0}, { 50, 50});
    Hero->addComponent(new InputComponent(Hero));
    Hero->addComponent(new MovementsComponent(Hero,500));
    Hero->addComponent(new RenderFile(Hero, "Assets/Debug/Collider_DebugTX.png"));
    Hero->addComponent(new StateMachineComponent(Hero));
    
    myScene->addObject(Hero, 0);
}

std::unordered_map<std::string, Scene*> SceneReader::getScenes() {
    return scenesHUD;
}
