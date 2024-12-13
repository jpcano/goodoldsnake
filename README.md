# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## New feature added to the game

1. Apart from the arrow keys the user can control the snake with the "WASD" keys
2. Now there are three types of food: Green (1 point), Amber (2 points) and Red (3 points).
3. The user can pause the game by pressing the "p" key.
4. The game now saves the scores in a file and displays a scoreboard when the game exits.
5. When the snakes eats food, it needs 4 seconds to digest it. If a new food is eaten while the snake is digesting the previous food then the it dies.
6. Added CLI arguments to the executable:
   * `--name`: Sets the name of the player
   * `--file`: Sets the name of the file used to save the scores
   * `--scores`: View the scores ordered by points and snake's size
   * `--help`: Displays help information about how to use the CLI

## Rubric points addresed

1. README (All Rubric Points REQUIRED)
   * :white_check_mark: A README with instructions is included with the project: **This is what you are reading now.**
   * :white_check_mark: The README indicates the new features I added to the game. **See the previous section I added.**
   * :white_check_mark: The README includes information about each rubric point addressed. **See the next section I added.**

2. Compiling and Testing (All Rubric Points REQUIRED)
   * :white_check_mark: The submission must compile and run without errors on the Udacity project workspace: **I verified the the project compiles in the workspace without errors.**

3. Loops, Functions, I/O - meet at least 2 criteria
   * :white_check_mark: The project reads data from a file and process the data, or the program writes data to a file: **The game writes the scoreboard in a JSON file on the disk and it is read at the end of the game to display the scoreboard sorted by points.**
   * :white_check_mark: The project accepts user input and processes the input: **A new input was added ("p" key) that is used to pause the game.**

4. Object Oriented Programming - meet at least 3 criteria
   * :white_check_mark: One or more classes are added to the project with appropriate access specifiers for class members: **I added two new classes in total, `Food` and `Score`.**
   * :white_check_mark: Class constructors utilize member initialization lists: **Both `Food` and `Score` classes uses member initialization lists.**
   * :white_check_mark: Overloaded functions allow the same function to operate on different parameters: **The Score classes has several methods overloaded, for example `GetEntriesByScore()` is used to get all the entries sorted by score whereas `GetEntriesByScore(size_t limit)` is used to get limit number of entries ordered by score.**

5. Memory Management - meet at least 3 criteria
   * :white_check_mark: The project makes use of references in function declarations: **The class Score contains two functions that used references as arguments (ie. `SliceLimit()` and `Push()`).**
   * :white_check_mark: The project uses destructors appropriately. **The Scores clases saves the scores in a file in its destructor.**
   * :white_check_mark: The project uses smart pointers instead of raw pointers: **In `main.cpp`, the Scores instance is created with a unique pointer and therefore the file resource is protected.**

6. Concurrency - meet at least 2 criteria
   * :white_check_mark: The project uses multithreading: **The "digesting" timer is controlled by an independant thread created from the main thread.**
   * :white_check_mark: A mutex or lock is used in the project. **To guaranty that the snake digesting state and the head's color is synchronized properly a exclusive mutex is added to protected the read/write operations from different threads on the boolean digesting.**

## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
