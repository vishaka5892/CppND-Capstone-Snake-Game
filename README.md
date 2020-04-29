# CPPND: Capstone Snake Game Example

This C++ project is the final project of the Udacity C++ Nanodegree.
The source code has been adapted from the starter code located at (Udacity's repo)[https://github.com/udacity/CppND-Capstone-Snake-Game].


<img src="snake_game.gif"/>

There are four components: 

- Renderer component is responsible for rendering the state of the game using the popular [SDL library](https://www.libsdl.org/)
				
- Game component constructs and maintains the game board and placement of the game elements like the snake and food.

- Snake component constructs and maintains the snake object as it moves across the board gaining points and checking if it ate itself (ran into self).

- Controller component receives input from the user in order to control movement of the snake.

Upon game launch, the user is displayed with the detected platform being used for this project.

The user is asked for a name and upon receiving the input, 
the starting speed of the snake in the game is to be chosen by the user. 

The game board is launched once a valid speed from the range given, is chosen by the user. The user can move the snake around using arrow keys.

Upon exiting from the game by 1) pressing the "X" button the top right corner of the game board 
or 2) pressing ctrl+C in the terminal, 
a "QUIT" and "Game has terminated successfully!" messages are displayed on the terminal followed by the name of the user, points scored, size of the snake, distance of head travelled by the snake and time of the game.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Rubrics Items Satisfied
1. `Object Oriented Programming` - The project uses Object Oriented Programming techniques.`

> The project code has classes with class attributes to contain the data, and class methods to perform tasks.

To meet this requirement, a `Platform` class was created in `platform.h` to hold information about the system platform. The class uses the member functions `getPlatform` and `displayPlatform` to fetch and printout the user's detected system platform. Also a `Gamer` class was created inside in `user.h` to get the player's name, game time and player score.

2. `Object Oriented Programming` - Classes use appropriate access specifiers for class members.

> All class members are explicitly specified as public, protected or private.

3. `Loops, functions, I/O` - Project accepts user input and processes the input

> The project accepts input from the user as part of the program.

 Project lets the user to input their name and choose the starting speed of the snake.

4.  `Object Oriented Programming` - Class constructors utilize member initialization lists.

> All class members that are set to argument values are initialized through member initialization lists.

Within `platform.h` for the private variable `platform` the default argument is a null string which is set in the class's initiaziation list.

5. `Object Oriented Programming` - Classes abstract implementation details from their interfaces.

> All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways.

The C++ Guide by Google was used to for any needed documentation. An example can be found within `platform.h` where a simple comment is used to describe what the function `getPlatform` does. 

6. `Memory Management` - The project makes use of references in function declarations. 

> At least two variables are defined as references, or two functions use pass-by-reference in the project code.

An example of this can be seen in the declaration of the function HeadDistanceTravel() in snake.h

7. `Concurrency` - A mutex or lock is used in the project

> A mutex or lock (e.g. std::lock_guard or `std::unique_lock) is used to protect data that is shared across multiple threads in the project code.

To meet this requirement, a lock mechanism (lock_guard<std::mutex>) is used in renderer.cpp (line 83)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.