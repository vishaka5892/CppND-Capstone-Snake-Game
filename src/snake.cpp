#include "snake.h"
#include <cmath>
#include <iostream>

//Function to get the starting speed from the user
void Snake::SetStartSpeed()
{
  float usrSpeed;
  char rangeBuff[25];
  char usrAns[25];
  sprintf(rangeBuff, "%0.1f and %0.1f", minimumStartSpeed, maximumStartSpeed);
  std::string rangeStr(rangeBuff);

  std::cout << "\n" <<"It's Time For Fun! What Would You Like The Starting Speed Of The Snake Be?" << std::endl;
  std::cout << "Select A Number Between " << rangeStr << std::endl;

  while (true)
  {
    int userIn = scanf("%f", &usrSpeed);
    if (userIn)
    {
      if (usrSpeed >= minimumStartSpeed && usrSpeed <= maximumStartSpeed)
      {
        speed = usrSpeed;
        return;
      }
    }
    std::cerr << "\n"<< "Error! Please provide a valid value between " << rangeStr << std::endl;
  }
}

Snake::Snake(){};

void Snake::Update() {
  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)};  // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)};  // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
    UpdateBody(current_cell, prev_cell);
  }
}

float Snake::head_total_distance = 0;

void Snake::UpdateHead() {
  switch (direction) {
    case Direction::kUp:
      head_y -= speed;
      break;

    case Direction::kDown:
      head_y += speed;
      break;

    case Direction::kLeft:
      head_x -= speed;
      break;

    case Direction::kRight:
      head_x += speed;
      break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  head_x = fmod(head_x + grid_width, grid_width);
  head_y = fmod(head_y + grid_height, grid_height);

HeadDistanceCovered(head_total_distance, head_x, head_y, x_prev, y_prev);
}

void Snake::HeadDistanceCovered(float &head_total_distance, float head_x, float head_y, float &x_prev, float &y_prev)
{

  head_total_distance = head_total_distance + abs(head_x - x_prev) + abs(head_y - y_prev);
  x_prev = head_x;
  y_prev = head_y;
}

void Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell) {
  // Add previous head location to vector
  body.push_back(prev_head_cell);

  if (!growing) {
    // Remove the tail from the vector.
    body.erase(body.begin());
  } else {
    growing = false;
    size++;
  }

  // Check if the snake has died.
  for (auto const &item : body) {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
      alive = false;
    }
  }
}

void Snake::GrowBody() { growing = true; }

// Inefficient method to check if cell is occupied by snake.
bool Snake::SnakeCell(int x, int y) {
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
    return true;
  }
  for (auto const &item : body) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}
