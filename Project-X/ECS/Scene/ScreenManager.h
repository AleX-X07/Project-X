#pragma once
#include "../Object.h"

class Scene;
class SceneReader;

class ScreenManager : public Component {
private:
 
    Scene* currentScene;
    
    std::unordered_map<std::string, std::string> screen;
    std::string currentScreen;
    
public:
    ScreenManager(Object* _owner, Scene* scene, std::unordered_map<std::string, std::string> screen);
    virtual ~ScreenManager() override = default;
    
    void setScreen(std::string name);
    
    virtual void update(float deltaTime) override;
};
