#include "Animation.h"

Animation::Animation(const char* path) {
    texture = new sf::Texture(path);
}

Animation::~Animation() {
    delete texture;
    texture = nullptr;
}

void Animation::update(float deltaTime) {
}

void Animation::render(RenderComponent& renderOwner) {
    renderOwner.setTexture(*texture);
}
