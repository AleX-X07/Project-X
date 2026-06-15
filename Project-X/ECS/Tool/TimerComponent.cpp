#include "TimerComponent.h"

TimerComponent::TimerComponent(Object* _owner, float _timer) : Component(_owner) {
    timer = _timer;
    
    if (!font.openFromFile("Assets/Font/Brown Cookies.otf")) {
        std::cerr << "Erreur : impossible de charger la police !" << std::endl;
    }
    text = new sf::Text(font);
    text->setPosition({500, 0});
    text->setCharacterSize(24);
    text->setFillColor(sf::Color::White);
}

TimerComponent::~TimerComponent() {
    delete text;
    text = nullptr;
}

void TimerComponent::update(float deltaTime) {
    actualTime += deltaTime;
    
    if (actualTime >= timer) {
        hasEnd = true;
    }
    
    int TextTimer = timer - actualTime;
    text->setString(std::to_string(TextTimer));
}

void TimerComponent::render() {
    // GameEngine::getWindow()->setView(GameEngine::getWindow()->getDefaultView());
    // GameEngine::getWindow()->draw(*text);
    //
    // auto cam = owner->getComponent<CameraComponent>();
    // if (cam != nullptr)
    // {
    //     GameEngine::getWindow()->setView(*cam->view);
    // }
}