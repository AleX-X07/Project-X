#pragma once
#include "../Object.h"

class Scene;
class SceneReader;

class ScreenManager : public Component {
private:
 
    Scene* currentScene;
    
    std::string nameWin;
    std::string nameDeath;
    std::string namePaused;
    std::string nameSettings;
    
public:
    ScreenManager(Object* _owner, Scene* scene);
    ScreenManager(Object* _owner, Scene* scene, std::string nameWin, std::string nameDeath, std::string namePaused, std::string nameSettings);
    virtual ~ScreenManager() override = default;
    
    void setScreen(std::string name);
    
    virtual void update(float deltaTime) override;
};
