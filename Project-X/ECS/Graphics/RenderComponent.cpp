#include "RenderComponent.h"
#include "../../Main/GameEngine.h"

RenderComponent::RenderComponent(Object* _owner, std::string name) : Component(_owner)
{
    setPathTexture(name);
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

void RenderComponent::setPathTexture(std::string _name) {
    if (texture.loadFromFile(_name)) {
        Rect.setTexture(&texture);
    }
}

void RenderComponent::setTexture(sf::Texture& _texture) {
    texture = _texture;
}
