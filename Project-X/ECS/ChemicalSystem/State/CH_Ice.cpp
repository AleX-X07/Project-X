#include "CH_Ice.h"
#include "../ChemicalManager.h"
#include "../../Behaviour/AiMoveTo.h"
#include "../../Graphics/RenderFile.h"
#include "../../Movement/MovementComponent.h"

CH_Ice::CH_Ice(ChemicalManager& _Manager, float _duration, float _power) : ElementMain(_Manager, _duration) {
    power = _power;
    
    auto comp = Manager.getOwner()->getComponent<RenderFile>();
    if (comp) {
        comp->getRect()->setFillColor(sf::Color::Cyan);
    }
    
    file = "Assets/EffectIcon/IceIcon.png";
    
    auto move = Manager.getOwner()->getComponent<MovementsComponent>();
    if (move) {
        move->setSpeed(move->getSpeed() / power);
    }
    
    auto Ai = Manager.getOwner()->getComponent<AiMoveTo>();
    if (Ai) {
        Ai->speed = Ai->speed / power;
    }
}

void CH_Ice::update(float dt) {
    actualtime += dt;
    if (actualtime > duration) {
        actualtime = 0;
        
        auto render = Manager.getOwner()->getComponent<RenderFile>();
        if (render) {
            render->getRect()->setFillColor(sf::Color::White);
        }
        
        
        auto move = Manager.getOwner()->getComponent<MovementsComponent>();
        if (move) {
            move->setSpeed(move->getSpeed() * power);
        }
        auto Ai = Manager.getOwner()->getComponent<AiMoveTo>();
        if (Ai) {
            Ai->speed = Ai->speed * power;
        }
        
        isactive = false;
    }
}
