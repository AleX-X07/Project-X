#pragma once
#include "../State.h"
#include "IdleLeftState.h"
#include "LeftState.h"

class RightState : public State {
public:
    RightState(Object* owner, std::unordered_map<std::string,nlohmann::basic_json<>>* _mapAnimation);
    virtual ~RightState() override = default;
    
    virtual void update(float deltaTime) override;
};
