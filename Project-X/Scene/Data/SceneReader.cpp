#include "SceneReader.h"

#include "../../Main/GameEngine.h"

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
                        
                        if (FactoriesECS::factories.count(name)) {
                            newObj->addComponent(FactoriesECS::factories[name](newObj, ecs, addScene));
                        } else {
                            std::cerr << "Composant inconnu : " << name << std::endl;
                        }
                        if (name == "StateMachine") {
                            readAnimation(ecs, newObj);
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
            }
        }
    }
}

void SceneReader::readAnimation(nlohmann::basic_json<>& ecs, Object* newObj) {
    std::string fileName = std::string(ecs["args"][0]) + ".json";
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
    if (newObj->hasComponent<StateMachineComponent>()) {
        newObj->getComponent<StateMachineComponent>()->setSM(myMap,mapState,dataFirstState);
    }
}

void SceneReader::SceneTestDev() {
    Scene* addScene = new Scene(2);
    addScene->setLayer(2);
    GameEngine::getVecState().push_back(addScene);
    
    // DebugMap for dev only
    Object* Map = new Object({0, 0}, { 1920*2, 1080*2});
    Map->addComponent(new RenderComponent(Map, "Assets/Debug/map.png"));
    addScene->addObject(Map, 1);
    // End Debug
    
    Object* newObj = new Object({200, 200}, { 50, 50});
    Object* Hurt = new Object({0, 0}, { 50, 50});
    
    auto* spawner = new AiMobSpawner(Hurt, {1920*2, 1080*2}, addScene->getVecObjects());
    Hurt->addComponent(spawner);

    newObj->team = Object::Team::Player;

    newObj->addComponent(new InputComponent(newObj));
    newObj->addComponent(new RenderComponent(newObj, "Assets/Character/hero1.png"));
    newObj->addComponent(new MouseComponent(newObj));
    newObj->addComponent(new MovementsComponent(newObj, 500));
    newObj->addComponent(new BulletManager(newObj));
    newObj->addComponent(new WeaponMain(newObj, "Assets/WeaponTxt/Deagle.txt"));
    newObj->addComponent(new HurtBox(newObj, {50, 50}, addScene->getVecObjects(), 1));
    newObj->addComponent(new CameraComponent(newObj, 1920, 1080, 1920*2, 1080*2, false, 5));
    newObj->addComponent(new HealthComponent(newObj, 1000, addScene->getVecObjects()));
    newObj->addComponent(new ExpManager(newObj));
    newObj->addComponent(new DebugHudComp(newObj));
    newObj->addComponent(new CrossHairComponent(newObj));

    addScene->addObject(newObj, 1);
    addScene->addObject(Hurt, 1);
}

void SceneReader::SceneTestDev2() {
    Scene* myScene = new Scene(0);
    myScene->setLayer(2);
    GameEngine::getVecState().push_back(myScene);
    
    Object* Hero = new Object({0, 0}, { 50, 50});
    Hero->addComponent(new InputComponent(Hero));
    Hero->addComponent(new MovementsComponent(Hero,500));
    Hero->addComponent(new RenderComponent(Hero, "Assets/Debug/Collider_DebugTX.png"));
    Hero->addComponent(new StateMachineComponent(Hero));
    
    myScene->addObject(Hero, 0);
}
