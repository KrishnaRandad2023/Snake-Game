# Snake Game in C++

This is a simple implementation of the classic Snake game using C++. The game is played on a console where you control a snake to eat fruits and grow. The game ends when the snake collides with the boundary or itself.

## Features

- Snake movement in four directions (up, down, left, right)
- A randomly appearing fruit that the snake must eat
- Snake grows longer each time it eats a fruit
- Simple console graphics with a border and score display
- Game ends if the snake hits the border or its own body

## Controls

- **W**: Move Up
- **A**: Move Left
- **S**: Move Down
- **D**: Move Right

## How to Run

### Prerequisites

To compile and run this game, you need:
- A C++ compiler (e.g., g++)
- A Windows environment, as the game uses Windows-specific libraries like `<windows.h>` for cursor control.

### Compilation Instructions

1. Open your terminal/command prompt.
2. Navigate to the directory where the source code (`snake.cpp`) is located.
3. Compile the program using the following command:
   ```
   g++ -o snake_game snake.cpp
   ```
4. Run the game:
   ```
   ./snake_game
   ```

### Gameplay

1. The game starts with the snake positioned in the center of the game area.
2. Use the control keys (W, A, S, D) to move the snake.
3. Eat the fruit (F) to gain points and grow the snake's tail.
4. Avoid hitting the boundaries or the snake's own body.
5. The game continues until the snake collides with the border or itself.

## Improvements

Here are some future enhancements you can make:
- **Graphics**: The current version uses ASCII characters for borders, the snake, and fruits. A graphical UI using a library like SFML could improve the visuals.
- **Game Modes**: Add difficulty levels (faster snake movement, more obstacles).
- **Sound**: Add sound effects for eating fruits or hitting the boundary.
- **Port to Other Platforms**: Port the game to other platforms, such as a web-based version using JavaScript and p5.js.

## Code Explanation

- The game uses an infinite `while` loop to keep running until the game is over.
- The `draw()` function draws the game board, including the snake's head, tail, fruit, and border.
- The `input()` function captures the user’s input (W, A, S, D) to move the snake.
- The `logic()` function handles the snake's movement, checks for collisions, and updates the game state (tail, fruit, score).

## Contributions

Contributions are welcome! Feel free to fork the project, make improvements, and submit pull requests.

---
