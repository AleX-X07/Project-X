#include "Quit.h"

#include "../../Main/GameEngine.h"

Quit::Quit(Object* _owner) : Component(_owner){
}

void Quit::update(float deltaTime) {
    GameEngine::getWindow()->close();
}
