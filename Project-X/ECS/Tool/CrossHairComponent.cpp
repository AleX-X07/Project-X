#include "CrossHairComponent.h"

#include "../../Main/GameEngine.h"
#include "../Graphics/RenderFile.h"
#include "../Input/MouseComponent.h"

CrossHairComponent::CrossHairComponent(Object* _owner) : Component(_owner) {
    Cross = new Object({0 ,0}, {25, 25});
    Cross->addComponent(new RenderFile(Cross, "Assets/Debug/CrossHair.png"));
}

CrossHairComponent::~CrossHairComponent() {
    delete Cross;
    Cross = nullptr;
}

void CrossHairComponent::update(float deltaTime) {
    
    GameEngine::getWindow()->setMouseCursorVisible(false);
    Cross->update(deltaTime);
    
    Xjoystick = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U);
    Yjoystick = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::V);

    if (sf::Joystick::isConnected(0) && (std::abs(Xjoystick) > 20 || std::abs(Yjoystick) > 20)) {
        float angleRad = std::atan2(Yjoystick, Xjoystick);
        sf::Vector2f dir(std::cos(angleRad), std::sin(angleRad));
        sf::Vector2f playerPos = owner->getPosition();
        float distance = 150.f;
        sf::Vector2f crossPos = playerPos + dir * distance;

        Cross->setPosition(crossPos);
    }
    
    else {
        auto comp = owner->getComponent<MouseComponent>();
        if (comp !=nullptr) {
            sf::Vector2i pixelPos = comp->getMousePosition();
            sf::Vector2f worldPos = GameEngine::getWindow()->mapPixelToCoords(pixelPos);
            Cross->setPosition({(worldPos.x - 25/2), (worldPos.y - 25/2)});
        }
    }
}

void CrossHairComponent::render() {
    Cross->render();
}
