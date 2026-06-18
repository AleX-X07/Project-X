#include "SceneReader.h"

#include "../ECS/Tool/TimerComponent.h"
#include "../Main/GameEngine.h"

SceneReader* SceneReader::myInstance = nullptr;

void SceneReader::read() {
    inputReader.read();
    weaponReader.read();
    readScene();
}

void SceneReader::readScene() {
    std::ifstream scene("Data/Scene/SceneManager.json");
    if (scene.is_open()) {
        nlohmann::json data = nlohmann::json::parse(scene);
        nlohmann::json currentScene = data["Scene"];
        for (auto& s : currentScene) {
            std::string file = s.get<std::string>() + ".json";
            std::string path = "Data/Scene/Scene/" + file;
            std::ifstream currentSceneOpen(path);
            
            if (currentSceneOpen.is_open()) {
                nlohmann::json data2 = nlohmann::json::parse(currentSceneOpen);
                GameEngine::getMapScene()[data2["ID"]] = data2["Name"];
            }
        }
    }
}

Scene* SceneReader::initScene(int idScene) {
    std::string file = GameEngine::getMapScene()[idScene] + ".json";
    std::string path = "Data/Scene/Scene/" + file;
    std::ifstream currentScene(path);
    
    if (currentScene.is_open()) {
        nlohmann::json data = nlohmann::json::parse(currentScene);
    
        Scene* newScene = new Scene(idScene);
        newScene->setLayer(data["Layer"]);
        
        nlohmann::json objects = data["Objects"];
        
        for (auto& obj : objects) {
            MapMakeComponent* map = nullptr;
            Object* newObj = new Object({obj["Position"][0],obj["Position"][1]},{obj["Size"][0],obj["Size"][1]});
            newObj->setName(obj["Name"]);
            newObj->setDescription(obj["Description"]);            
            
            if (obj["Team"] == "Player") {
                newObj->team = Object::Team::Player;
            }
            else if (obj["Team"] == "Enemy") {
                newObj->team = Object::Team::Enemy;
            }
            else if (obj["Team"] == "Map") {
                newObj->team = Object::Team::Map;
            }
            else {
                newObj->team = Object::Team::Neutral;
            }
                    
            for (auto& ecs : obj["ECS"]) {
                std::string name = ecs["Component"];
                if (name == "Clone") {
                    int nbr = ecs["args"][0];
                    auto* cloneComp = new CloneItemComponent(newObj, newScene, nbr, obj);
                    newObj->addComponent(cloneComp);
                    cloneComp->clone(); 
                    continue;
                }
                if (FactoriesECS::factories.count(name)) {
                    newObj->addComponent(FactoriesECS::factories[name](newObj, ecs, newScene));
                } else {
                    std::cerr << "Composant inconnu : " << name << std::endl;
                }
                
                if (name =="StateMachine") {
                    readAnimation(ecs,newObj);
                }
                if (name == "HUD") {
                    readHUD(ecs,newObj,newScene);
                }
                if (name == "Map") {
                    map = newObj->getComponent<MapMakeComponent>();
                }
            }
            if (newObj->team != Object::Team::Map) {
                newObj->setLayer(obj["LayerPosition"]);
                newScene->addObject(newObj, newObj->getLayer());
            }
            else {
                makeMap(map, newObj);
            }
        }
        return newScene;
    }
    return nullptr;
}

std::vector<Object*>* SceneReader::initScreen(std::string nameScreen, Scene* currentScene) {
    std::vector<Object*>* myObjects = new std::vector<Object*>;
    
    std::string file = nameScreen + ".json";
    std::string path = "Data/Scene/Screen/" + file;
    std::ifstream screen(path);
    
    if (screen.is_open()) {
        nlohmann::json data = nlohmann::json::parse(screen);
        
        for (auto& obj : data["Objects"]) {
            Object* newObj = new Object({obj["Position"][0],obj["Position"][1]},{obj["Size"][0],obj["Size"][1]});
            
            if (obj["Team"] == "Player") {
                newObj->team = Object::Team::Player;
            }
            else if (obj["Team"] == "Enemy") {
                newObj->team = Object::Team::Enemy;
            }
            else {
                newObj->team = Object::Team::Neutral;
            }
                    
            for (auto& ecs : obj["ECS"]) {
                std::string name = ecs["Component"];
                        
                if (FactoriesECS::factories.count(name)) {
                    newObj->addComponent(FactoriesECS::factories[name](newObj, ecs, currentScene));
                } else {
                    std::cerr << "Composant inconnu : " << name << std::endl;
                }
                
                if (newObj->hasComponent<StateMachine>()) {
                    readAnimation(ecs,newObj);
                }
                if (newObj->hasComponent<HUD>()) {
                    readHUD(ecs,newObj,currentScene);
                }
            }
            myObjects->push_back(newObj);
        }
    }
    return myObjects;
}

void SceneReader::makeMap(MapMakeComponent* map, Object* newObj) {
    if (map != nullptr) {
        map->getMaker()->getItemMap().push_back(newObj);
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
    Scene* addScene = new Scene(0);
    addScene->setLayer(2);
    
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

    newObj->addComponent(new CapacityManager(newObj));
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
    
    //newObj->addComponent(new ScreenManager(newObj, addScene));
    
    addScene->addObject(newObj, 1);
    addScene->addObject(Hurt, 1);
    addScene->addObject(Exp, 1);
}

SceneReader* SceneReader::getInstance() {
    if (myInstance == nullptr) {
        myInstance = new SceneReader();
    }
    return myInstance;
}

