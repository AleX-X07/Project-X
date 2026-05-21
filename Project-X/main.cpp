#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Source/InputComponent.h"
#include "Source/MovementComponent.h"
#include "Source/Object.h"
#include "Source/RenderCompononent.h"

int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), "SFML window");
    
    gameObject test({0, 0}, {50, 50});
    
    test.addComponent(new InputComponent(&test));
    test.addComponent(new RenderCompononent(&test, "Sprite/Debug/Baker.png"));
    test.addComponent(new movementsComponent(&test, 500));
    
    sf::Clock clock;
    
    // Start the game loop
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        
        // Process events
        while (const std::optional event = window.pollEvent())
        {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // Clear screen
        window.clear();

        // Update the window
        test.update(dt);
        test.render(window);
        
        window.display();
    }
}
