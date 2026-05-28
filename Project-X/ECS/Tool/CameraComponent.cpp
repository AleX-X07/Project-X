#include "CameraComponent.h"

#include "../../Main/GameEngine.h"

CameraComponent::CameraComponent(Object* _owner, float ScreenX, float ScreenY, float LevelX, float LevelY, bool _hasLag, float lagfactor)  : Component(_owner) {
    view = new sf::View({ ScreenX / 2, ScreenY / 2 }, { ScreenX, ScreenY });
    lag = lagfactor;
    ScreenSize = { ScreenX, ScreenY };
    LevelSize = { LevelX, LevelY };
    haslag = _hasLag;
}

CameraComponent::~CameraComponent()
{
    delete view;
    view = nullptr;
}

void CameraComponent::update(float dt) {
    if (haslag)
    {
        ObjectivePos = { owner->getPosition().x + owner->getSize().x / 2, owner->getPosition().y + owner->getSize().y / 2 };

        ObjectivePos.x = std::max(ScreenSize.x / 2, std::min(ObjectivePos.x, LevelSize.x - ScreenSize.x / 2));
        ObjectivePos.y = std::max(ScreenSize.y / 2, std::min(ObjectivePos.y, LevelSize.y - ScreenSize.y / 2));

        sf::Vector2f current = view->getCenter();
        current.x += (ObjectivePos.x - current.x) * lag * dt;
        current.y += (ObjectivePos.y - current.y) * lag * dt;

        view->setCenter(current);
        pos = current;
    
        GameEngine::getWindow()->setView(*view);
    }
    else
    {
        view->setCenter({owner->getPosition().x + owner->getSize().x / 2, owner->getPosition().y + owner->getSize().y / 2});
        GameEngine::getWindow()->setView(*view);
    }
}