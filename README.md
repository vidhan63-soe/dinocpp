# dinocpp
It is chrome game made in cpp.
This game is a simple console-based running and jumping game implemented in C++.

### Game Summary

- **Objective**: The player controls a character that must avoid obstacles by jumping over them. The game ends if the character collides with an obstacle.
- **Controls**:
  - Press **Space** to make the character jump.
  - Press **X** to exit the game.

### Game Mechanics

1. **Setup**:
   - The game window is cleared and resized.
   - Initial game instructions and score display are set up.

2. **Game Loop**:
   - The game runs in a continuous loop.
   - The character and obstacles are repeatedly drawn on the screen.
   - The character automatically moves forward, and obstacles appear from the right side of the screen and move left.
   - If no key is pressed, the character keeps running.
   - If the space key is pressed, the character jumps. The jump is split into an ascending and descending phase to simulate a jump arc.
   - If the character collides with an obstacle, the game displays "Game Over" and waits for a key press before resuming.

3. **Jumping**:
   - The jump is handled by changing the character's vertical position.
   - The jump consists of two phases: going up (10 iterations) and coming down (10 iterations).

4. **Obstacles**:
   - Obstacles appear at a fixed position and move left towards the character.
   - If the obstacle reaches the leftmost part of the screen, it resets to the right side.
   - The speed of the game increases gradually as the player progresses.

5. **Collision Detection**:
   - If an obstacle reaches the character's horizontal position and the character is not high enough (i.e., not jumping), it is considered a collision, and the game ends.

6. **Score**:
   - The score increases as the player successfully avoids obstacles.
   - The score is displayed on the screen.

### Functions and their Roles

- `gotoxy(int x, int y)`: Moves the cursor to position `(x, y)` on the console.
- `delay(unsigned int mseconds)`: Pauses the program for the specified number of milliseconds.
- `getup()`: Sets up the initial game screen and prints instructions.
- `ds(int jump)`: Draws the character on the screen. Handles the character's jump and running animations.
- `obj()`: Draws and moves the obstacles. Handles collision detection and score updating.

### Notes
- The game is designed to run in a Windows console environment.
- For Unix-like systems, an alternative implementation using `ncurses` can be used for compatibility.

### Dependencies

- **Windows**: Uses `windows.h`, `conio.h` for console manipulation and keyboard input.
- **Unix-like Systems**: Requires `ncurses` library for similar functionality.

