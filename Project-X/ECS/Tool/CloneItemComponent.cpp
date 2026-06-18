#include "CloneItemComponent.h"
#include "../../Reader/SceneReader.h"

CloneItemComponent::CloneItemComponent(Object* _owner, Scene* _currentScene, nlohmann::json _data) : CloneItemComponent(_owner, _currentScene, 1, _data){
}

CloneItemComponent::CloneItemComponent(Object* _owner, Scene* _currentScene, int nbr, nlohmann::json _data) : Component(_owner), nbrClone(nbr), currentScene(_currentScene), dataClone(_data){
}

void CloneItemComponent::clone() {
    for (int X = 0; X < nbrClone; X++) {
        Object* clone = new Object();
        clone->setName(owner->getName());
        clone->setLayer(owner->getLayer());
        clone->team = owner->team;
        clone->setSize(owner->getSize());
        
        for (auto& ecs : dataClone["ECS"]) {
            std::string name = ecs["Component"];
            if (name == "Clone") continue; 
            if (FactoriesECS::factories.count(name)) {
                clone->addComponent(FactoriesECS::factories[name](clone, ecs, currentScene));
            }
            if (name == "StateMachine") {
                SceneReader::getInstance()->readAnimation(ecs, clone);
            }
            if (name == "HUD") {
                SceneReader::getInstance()->readHUD(ecs, clone, currentScene);
            }
        }
        currentScene->addObject(clone, clone->getLayer());
    }
}