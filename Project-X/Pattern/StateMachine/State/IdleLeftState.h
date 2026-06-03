#pragma once
#include "../State.h"

class IdleLeftState : public State {
public:
    IdleLeftState(Object* owner, std::unordered_map<std::string,nlohmann::basic_json<>>* _mapAnimation);
    virtual ~IdleLeftState() override = default;
    
    virtual void update(float deltaTime) override;
};
