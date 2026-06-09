#pragma once
#include <iostream>
#include <SFML/Graphics/Font.hpp>
#include "../Object.h"

class GameEngine;

class RenderText : public Component{
private:
    sf::Font myFont;
    sf::Text* myText;
public:
    RenderText(Object* _owner, std::string file);
    virtual ~RenderText() override;
    
    virtual void update(float deltaTime) override;
    virtual void render() override;
    
    sf::Text* getText();
    
    void setText(std::string text);
};
