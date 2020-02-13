
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
    void setPosition(float, float);
    void setSpeed(float, float);
    void changePosition(float, float);
    sf::RectangleShape getSprite();
    Entity(float, float, sf::Color);
    

private:
    float xPosition;
    float yPosition;
    float xSpeed;
    float ySpeed;
    sf::RectangleShape sprite;
};

Entity::Entity(float x, float y, sf::Color color) {
    // Initialize the sprite
    xPosition = x;
    yPosition = y;
    sprite.setPosition(xPosition, yPosition);
    sprite.setSize(sf::Vector2f(60, 60));
    sprite.setFillColor(color);
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



int render(sf::RenderWindow &window, Entity &player, Entity &enemy);

int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    
    Entity player(100, 100, sf::Color::White);
    Entity enemy(400, 400, sf::Color::Blue);
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    if (render(window, player, enemy) == 0) {
        return EXIT_SUCCESS;
    }
    return 1;
}


int render(sf::RenderWindow &window, Entity &player, Entity &enemy) {
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
                
                if (event.type == sf::Event::KeyPressed) {
                    // Escape pressed: exit
                    if(event.key.code == sf::Keyboard::Escape) {
                        window.close();
                    }
                    
                    // WASD: Move the player around
                    if (event.key.code == sf::Keyboard::D) {
                        player.changePosition(4, 0);
                    }
                    
                    if (event.key.code == sf::Keyboard::A) {
                        player.changePosition(-4, 0);
                    }
                    
                    if (event.key.code == sf::Keyboard::S) {
                        player.changePosition(0, 4);
                    }
                    
                    if (event.key.code == sf::Keyboard::W) {
                        player.changePosition(0, -4);
                    }
                    
                    // Space: Shoot projectiles
                    if (event.key.code == sf::Keyboard::Space) {
                        // Let's shoot some projectiles
                        std::cout << "Bang! Bang!\n";
                    }
                }
                
                // Let's check for collision
                // If player.x is inside enemy.x + enemy.size.x
                // or if player.y is inside enemy.y + enemy.size.y
                // We know it's touching the enemy
                //

            }

            // Clear screen
            window.clear();

            // Draw to the window
            window.draw(enemy.getSprite());
            window.draw(player.getSprite());

            // Update the window
            window.display();
        }
    
    return 0;
}

// Next:
// Let's roll out a projectile
// Let's use a custom physics class for that
// After the physics calculations are done, the scene is calculated
// and it is sent to be drawn.

// After that let's roll out a time engine!
// Let's you manipulate time however you want.
