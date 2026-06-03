#pragma once
#include "../State.h"

class LeftState : public State {
public:
    LeftState(Object* owner, std::unordered_map<std::string,nlohmann::basic_json<>>* _mapAnimation);
    virtual ~LeftState() override = default;
    
    virtual void update(float deltaTime) override;
};
