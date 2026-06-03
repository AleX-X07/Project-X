#pragma once
#include "../State.h"
#include "RightState.h"
#include "LeftState.h"

class IdleRightState : public State {
public:
    IdleRightState(Object* owner, std::unordered_map<std::string,nlohmann::basic_json<>>* _mapAnimation);
    virtual ~IdleRightState() override = default;
    
    virtual void update(float deltaTime) override;
};
