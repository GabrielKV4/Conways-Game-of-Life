#include "Grid.h"

void Grid::createGrid() {

    lines.clear();

    float currentWidth = cellWidth;
    float currentHeight = cellHeight;

    // Add vertical lines
    while (currentWidth < window.getWidth()) {
        std::array line = {sf::Vertex{sf::Vector2f(currentWidth, 0.0f) } , sf::Vertex{sf::Vector2f(currentWidth, window.getHeight()) } };
        lines.push_back(line);

        currentWidth += cellWidth;
    }

    // Add horizontal lines
    while (currentHeight < window.getHeight()) {
        std::array line = {sf::Vertex{sf::Vector2f(0.0f, currentHeight) } , sf::Vertex{sf::Vector2f(window.getWidth(), currentHeight) } };
        lines.push_back(line);

        currentHeight += cellHeight;
    }
}

void Grid::drawGrid() {
    // Draw grid of lines
    for (auto line : lines) {
        window.draw(line.data(), line.size(), sf::PrimitiveType::Lines);
    }
}

Grid::Grid(int gridWidth, int gridHeight, float cellWidth, float cellHeight, const Window& window) : window(window) {
    this->gridWidth = gridWidth;
    this->gridHeight = gridHeight;
    this->cellWidth = cellWidth;
    this->cellHeight = cellHeight;

    createGrid();
}

void Grid::changeGridSize(int gridWidth, int gridHeight) {
    this->gridWidth = gridWidth;
    this->gridHeight = gridHeight;

    createGrid();
}

void Grid::changeCellSize(float newCellWidth, float newCellHeight) {
    this->cellWidth = newCellWidth;
    this->cellHeight = newCellHeight;

    createGrid();
}
