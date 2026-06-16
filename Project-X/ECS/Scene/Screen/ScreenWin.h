#pragma once
#include "../ScreenManager.h"
#include "../../Tool/TimerComponent.h"

class ScreenWin : public ScreenManager {
private:
    std::string file;
public:
    ScreenWin(Object* _owner, Scene* scene, std::string _file);
    virtual ~ScreenWin() override = default;
    
    virtual void update(float deltaTime) override;
};


