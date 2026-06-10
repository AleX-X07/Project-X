#pragma once
#include "../Object.h"

class Scene;
class SceneReader;

class LevelEnder : public Component {
private:
 
    Scene* currentScene;
    bool death;
    bool hasEnd;
    
public:
    LevelEnder(Object* owner, Scene* scene);
    virtual ~LevelEnder() override = default;
    
    void update(float deltaTime) override;
    void render() override;
};
