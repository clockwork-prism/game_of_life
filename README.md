# Game of Life
Simple C++ implementation of John Conway's Game of Life. Just a command line interface on a toroidal surface, future iterations may include a GUI and infinite field.

## How it works
The game has a glider and dodecahedron as written, currently modifying the starting board requires changing the code in main and rebuilding. The first major modification will be to read in the starting board from a .txt file instead. Running main will display the starting point, and ask for a number of steps. The program than runs the game of life algorithm for that many iterations and displays the result. 
