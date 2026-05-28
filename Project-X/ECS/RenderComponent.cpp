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
    // if (texture.getSize().x > 0 && texture.getSize().y > 0)
    // {
    //     Rect.setScale({owner->getSize().x / texture.getSize().x,
    //                    owner->getSize().y / texture.getSize().y});
    // }
}

void RenderComponent::render()
{
    GameEngine::getWindow()->draw(Rect);
}

void RenderComponent::setTexture(std::string _name) {
    if (texture.loadFromFile(_name)) {
        Rect.setTexture(&texture);
    }
}