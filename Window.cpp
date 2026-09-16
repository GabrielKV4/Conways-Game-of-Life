#include "Window.h"

Window::Window(int width, int height, int framerate) {
    // Initialize vars
    this->FRAMERATE = framerate;
    this->WIDTH = width;
    this->HEIGHT = height;

    // Set window size and create
    this->videoMode.size.x = width;
    this->videoMode.size.y = height;

    window = new sf::RenderWindow(videoMode, "Conway's Game of Life");
    window->setFramerateLimit(FRAMERATE);
    window->setKeyRepeatEnabled(false);
}

Window::~Window() {
    delete window;
}

int Window::getWidth() const {
    return static_cast<int>(this->WIDTH);
}

int Window::getHeight() const {
    return static_cast<int>(this->HEIGHT);
}

void Window::setWidth(int newWidth) {
    this->WIDTH = static_cast<unsigned>(newWidth);
}

void Window::setHeight(int newHeight) {
    this->HEIGHT = static_cast<unsigned>(newHeight);
}

void Window::setFramerate(int newFramerate) {
    this->FRAMERATE = newFramerate;
    this->window->setFramerateLimit(FRAMERATE);
}

bool Window::isRunning() {
    return window->isOpen();
}

void Window::draw(std::array<sf::Vertex, 2>::pointer data, std::size_t size, sf::PrimitiveType lines) const {
    window->draw(data, size, lines);
}

void Window::display() {
    window->display();
}

void Window::clear() {
    window->clear();
}

std::optional<sf::Event> Window::pollEvent() {
    return this->window->pollEvent();
}

void Window::close() {
    window->close();
}

void Window::draw(sf::RectangleShape& rectangle) {
    window->draw(rectangle);
}
