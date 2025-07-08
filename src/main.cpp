#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "stb_image.h"

int main()
{
    int HEIGHT = 600;
    int WIDTH = 800;

    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Ventana");

    sf::Texture texture;
    if (!texture.loadFromFile("../assets/textures/cell.png"))
    {
        return -1;
    }

    sf::Sprite cell;
    cell.setTexture(texture);

    sf::Vector2u textureSize = texture.getSize();

    cell.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
    cell.setPosition(WIDTH/2, HEIGHT/2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed) window.close();

        window.clear();

        window.draw(cell);

        window.display();
    }

    return 0;
}