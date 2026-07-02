#include "ClearSaveComponent.h"

#include "../Object.h"
#include "../../Writer/SaveWriter.h"
#include "../Input/MouseComponent.h"

ClearSaveComponent::ClearSaveComponent(Object* _owner) : Component(_owner){
}

void ClearSaveComponent::update(float deltaTime) {
    if (owner->getComponent<MouseComponent>()) {
        SaveWriter::getInstance()->clearSave();
    }
}
