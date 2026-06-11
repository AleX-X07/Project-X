#pragma once
#include "../Object.h"

class Scene;
class SceneReader;

class ScreenManager : public Component {
private:
 
    Scene* currentScene;
    bool death;
    bool hasEnd;
    
public:
    ScreenManager(Object* owner, Scene* scene);
    virtual ~ScreenManager() override = default;
    
    void update(float deltaTime) override;
};
