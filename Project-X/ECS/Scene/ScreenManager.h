#pragma once
#include "../Object.h"

class Scene;
class SceneReader;

class ScreenManager : public Component {
private:
    Scene* currentScene;
    std::vector<std::vector<Object*>*> previousScreen;
    bool screenSet;
    
public:
    ScreenManager(Object* _owner, Scene* scene);
    virtual ~ScreenManager() override = default;
    
    void setScreen(std::string name);
    Scene* getCurrentScene();
    std::vector<std::vector<Object*>*>& getPreviousScreen();
    
    void resetScreenSet();
};
