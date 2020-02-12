
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

// Render function with the main game loop.
// Will return

// Entity class is our main game class.
class Entity {
public:
    void setPosition(float x, float y);
    void setSpeed(float x, float y);
    void changePosition(float x, float y);
    sf::RectangleShape getSprite();
    Entity();
    

private:
    float xPosition = 10;
    float yPosition = 10;
    float xSpeed;
    float ySpeed;
    sf::RectangleShape sprite;
};

Entity::Entity() {
    // Initialize the sprite
    sprite.setPosition(xPosition, yPosition);
    sprite.setSize(sf::Vector2f(60, 60));
    sprite.setFillColor(sf::Color::White);
}

void Entity::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void Entity::changePosition(float x, float y) {
    xPosition += x;
    yPosition += y;
    setPosition(xPosition, yPosition);
}

void Entity::setSpeed(float x, float y) {
    xSpeed = x;
    ySpeed = y;
}

sf::RectangleShape Entity::getSprite() {
    return sprite;
}

// Need to write up the specs for the physics manager
class PhysicsManager {
    
};



int render(sf::RenderWindow &window, Entity &player);

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    
    Entity player;
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    if (render(window, player) == 0) {
        return EXIT_SUCCESS;
    }
    return 1;
}


int render(sf::RenderWindow &window, Entity &player) {
        // Start the game loop
        while (window.isOpen())
        {
            // Process events
            sf::Event event;
            while (window.pollEvent(event))
            {
                // Close window: exit
                if (event.type == sf::Event::Closed) {
                    window.close();
                }

                // Escape pressed: exit
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
                
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D) {
                    player.changePosition(4, 0);
                }
                
                if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A) {
                    player.changePosition(-4, 0);
                }
            }

            // Clear screen
            window.clear();

            // Draw to the window
            window.draw(player.getSprite());

            // Update the window
            window.display();
        }
    
    return 0;
}
