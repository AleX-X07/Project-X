#pragma once
#include "../ScreenManager.h"
#include "../../../Reader/WeaponReader.h"

class ScreenSpellChoice : public ScreenManager {
private:
    std::string file;
public:
    ScreenSpellChoice(Object* _owner, Scene* scene, std::string file);
    virtual ~ScreenSpellChoice() override = default;
    
    virtual void update(float deltaTime) override;
};

