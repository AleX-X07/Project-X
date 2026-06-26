#pragma once
#include "../ScreenManager.h"
#include "../../../Reader/WeaponReader.h"

class ScreenWeaponChoice : public ScreenManager {
private:
    std::string file;
public:
    ScreenWeaponChoice(Object* _owner, Scene* scene, std::string file);
    virtual ~ScreenWeaponChoice() override = default;
    
    virtual void update(float deltaTime) override;
};
