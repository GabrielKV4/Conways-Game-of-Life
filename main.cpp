#include <SFML/Graphics.hpp>
#include "Window.h"
#include "Grid.h"

int main() {

    // size of grid (Default 25x25)
    constexpr int gridWidth = 25;
    constexpr int gridHeight = 25;

    // size of each cell (Default 25x25)
    constexpr int cellWidth = 25;
    constexpr int cellHeight = 25;

    // Calculate optimal size of window to fit cells
    int WIDTH = gridWidth * cellWidth;
    int HEIGHT = gridHeight * cellHeight;

    Window window(WIDTH, HEIGHT, 12);

    // Create the grid
    Grid grid(gridWidth, gridHeight, cellWidth, cellHeight, window);

    bool simulationToggle = false;

    // Cell buffers
    std::vector<int> currentCells;
    const int columns = WIDTH / cellWidth;
    const int rows = HEIGHT / cellHeight;

    currentCells.resize(columns * rows);

    std::vector<int> nextCells = currentCells;

    while (window.isRunning()) {

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (const auto* mouseButton = event->getIf<sf::Event::MouseButtonPressed>())
            {
                if (mouseButton->button == sf::Mouse::Button::Left)
                {
                    int column = mouseButton->position.x / cellWidth;
                    int row = mouseButton->position.y / cellHeight;

                    int index = row * columns + column;

                    currentCells[index] = !currentCells[index];

                    nextCells = currentCells;
                }
            }

            if (const auto* key = event->getIf<sf::Event::KeyPressed>())
            {
                if (key->code == sf::Keyboard::Key::Space)
                {
                    simulationToggle = !simulationToggle;
                }
                if (key->code == sf::Keyboard::Key::Escape) {
                    window.close();
                }
                if (key->code == sf::Keyboard::Key::R) {
                    std::fill(nextCells.begin(), nextCells.end(), 0);
                }
            }

        }

        if (simulationToggle) {
            for (int i = 0; i < currentCells.size(); i++) {

                int aliveNeighbors = 0;

                int column = i % columns;
                int row = i / columns;

                for (int dy = -1; dy <= 1; dy++)
                {
                    for (int dx = -1; dx <= 1; dx++)
                    {
                        // Skip the current cell
                        if (dx == 0 && dy == 0)
                            continue;

                        int neighborColumn = column + dx;
                        int neighborRow = row + dy;

                        // Make sure the neighbor is inside the grid
                        if (neighborColumn < 0 || neighborColumn >= columns ||
                            neighborRow < 0 || neighborRow >= rows)
                            continue;

                        int neighborIndex = neighborRow * columns + neighborColumn;

                        if (currentCells[neighborIndex] == 1) {
                            aliveNeighbors += 1;
                        }
                    }
                }

                if (aliveNeighbors < 2) { // Underpopulation : Dies
                    nextCells[i] = 0;
                }else if (aliveNeighbors > 3) { // Overpopulation : Dies
                    nextCells[i] = 0;
                }else if (currentCells[i] == 1 and (aliveNeighbors == 2 or aliveNeighbors == 3)) { // Continues living
                    nextCells[i] = 1;
                }else if (currentCells[i] == 0 and aliveNeighbors == 3) { // Reproduction : new live cells
                    nextCells[i] = 1;
                }
            }
        }

        window.clear();

        // Cell drawing logic
        for (int i = 0; i < nextCells.size(); i++) {
            // Dead cell
            if (nextCells[i] == 0)
                continue;

            // Alive cell
            sf::RectangleShape rectangle({cellWidth, cellHeight});

            const float x = (i % columns) * cellWidth;
            const float y = (i / columns) * cellHeight;

            rectangle.setPosition(sf::Vector2f(x, y));
            window.draw(rectangle);
        }

        currentCells = nextCells;

        grid.drawGrid();

        window.display();
    }

    return 0;
}