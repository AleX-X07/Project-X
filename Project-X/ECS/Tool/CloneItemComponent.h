#pragma once
#include <nlohmann/json.hpp>

#include "../Component.h"
#include "../Object.h"
#include "../../Scene/Scene.h"
#include "../../Pattern/Factories.h"

class SceneReader;

class CloneItemComponent : public Component {
private:
    int nbrClone;
    Scene* currentScene;
    nlohmann::json dataClone;
    
public:
    CloneItemComponent(Object* _owner, Scene* _currentScene, nlohmann::json _data);
    CloneItemComponent(Object* _owner, Scene* _currentScene, int nbr, nlohmann::json _data);
    virtual ~CloneItemComponent() override = default;
    
    void clone();
};
