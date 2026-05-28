#include "RenderComponent.h"
#include "../Main/GameEngine.h"

RenderComponent::RenderComponent(Object* _owner, std::string name) : Component(_owner)
{
    setTexture(name);
    Rect.setPosition(owner->getPosition());
    Rect.setSize({owner->getSize().x, owner->getSize().y});
}

void RenderComponent::update(float deltaTime)
{
    Rect.setPosition(owner->getPosition());
}

void RenderComponent::render()
{
    GameEngine::getWindow()->draw(Rect);
}

void RenderComponent::setTexture(std::string _name)

{
    if (texture.loadFromFile(_name)) {
        Rect.setTexture(&texture);
    }
}