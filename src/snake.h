#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include "SDL.h"

class Snake {
 public:
  Snake();
  enum class Direction { kUp, kDown, kLeft, kRight };

  Snake(int grid_width, int grid_height)
      : grid_width(grid_width),
        grid_height(grid_height),
        head_x(grid_width / 2),
        head_y(grid_height / 2), 
        x_prev(grid_width / 2), 
  		  y_prev(grid_height / 2) {}

  void Update();
  //Ask user to set the starting speed of the snake
  void SetStartSpeed();
  void GrowBody();
  bool SnakeCell(int x, int y);

 void HeadDistanceCovered(float &h_tot_dist, float h_x, float head_y, float &x_prev, float &y_prev);
  
  Direction direction = Direction::kUp;

  float speed{0.1f};
  int size{1};
  bool alive{true};
  float head_x;
  float head_y;
  float x_prev;
  float y_prev;
  static float head_total_distance;

  std::vector<SDL_Point> body;
 
 private:
  void UpdateHead();
  void UpdateBody(SDL_Point &current_cell, SDL_Point &prev_cell);

  bool growing{false};
  int grid_width;
  int grid_height;
  float minimumStartSpeed{0.1};
  float maximumStartSpeed{0.6};
};

#endif