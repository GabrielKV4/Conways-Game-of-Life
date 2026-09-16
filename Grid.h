#pragma once
#include "Window.h"

class Grid {

private:
    int gridWidth;
    int gridHeight;
    float cellWidth;
    float cellHeight;

    std::vector<std::array<sf::Vertex,2>> lines;

    const Window& window;

    void createGrid();


public:

    Grid(int gridWidth, int gridHeight, float cellWidth, float cellHeight, const Window& window);
    void changeGridSize(int gridWidth, int gridHeight);
    void changeCellSize(float newCellWidth, float newCellHeight);
    void drawGrid();

};
