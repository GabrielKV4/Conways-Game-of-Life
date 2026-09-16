#pragma once

#include <SFML/Graphics.hpp>


class Window {
private:
    sf::RenderWindow* window;
    sf::VideoMode videoMode;

    unsigned WIDTH;
    unsigned HEIGHT;

    int FRAMERATE;

public:
    Window(int width, int height, int framerate = 12);
    ~Window();

    int getWidth() const;
    int getHeight() const;
    void setWidth(int newWidth);
    void setHeight(int newHeight);
    void setFramerate(int newFramerate);
    bool isRunning();
    void draw(sf::RectangleShape& rectangle);

    void draw(std::array<sf::Vertex, 2>::pointer data, std::size_t size, sf::PrimitiveType lines) const;

    void display();
    void clear();

    std::optional<sf::Event> pollEvent();

    void close();
};
