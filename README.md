# Conways-Game-of-Life
A Conway's Game of Life simulation built in C++ using sfml

## Features
- Interactive cell placement using the mouse
- Start and pause the simulation
- Clear the grid
- Real-time cell updates based on Conway's Game of Life rules
- Customizable grid and cell sizes

## Download

### Requirements
- C++ compiler (C++17 or later)
- CMake
- SFML 3.0.2
- Git

### Installation (macOS)

Install the dependencies using Homebrew:

```bash
brew install cmake sfml
```

### Clone the Repository

```bash
git clone "https://github.com/GabrielKV4/Conways-Game-of-Life.git"
cd Conways-Game-of-Life
```

### Build the Program

```bash
cmake -S . -B build
cmake --build build
```

### Run the Program

Run the executable generated inside the `build` directory;

```bash
./build/Conway_s_Game_of_Life
```

## Grid Customization

You can change the grid dimensions and cell sizes in `main.cpp`

```cpp
// size of grid (Default 25x25)
constexpr int gridWidth = 25;
constexpr int gridHeight = 25;

// size of each cell (Default 25x25)
constexpr int cellWidth = 25;
constexpr int cellHeight = 25;
```

- `gridWidth` : Number of columns in the grid.
- `gridHeight` : Number of rows in the grid.
- `cellWidth` : Width of each cell in pixels.
- `cellHeight` : Height of each cell in pixels.

The window size is calculated automatically based on the grid dimensions and cell sizes.

## Controls
| Key / Input | Action |
| --- | --- |
| Left Mouse Button | Toggle selected cell |
| Space | Start / Pause simulation |
| R | Clear the grid |
| Escape | Close the application |

## Conway's Game of Life

The simulation follows four rules:

1. A live cell with fewer than two neighbors dies from underpopulation.
2. A live cell with two or three neighbors lives to the next generation.
3. A live cell with more than three neighbors dies from overpopulation.
4. A dead cell with exactly three living neighbors becomes a live cell.

## Future Improvements
- Adjustable simulation speed
- Improved user interface
