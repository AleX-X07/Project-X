#pragma once
#include "../ScreenManager.h"
#include "../../../Tool/Input.h"

class ScreenPaused : public  ScreenManager{
private:
    std::string file;
public:
    ScreenPaused(Object* _owner, Scene* scene, std::string _file);
    virtual ~ScreenPaused() override = default;
    
    virtual void update(float deltaTime) override;
};
