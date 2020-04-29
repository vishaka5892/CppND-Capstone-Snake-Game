#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "user.h"
#include "platform.h"
#include "snake.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  //game stat
  Platform data;
  data.displayPlatform();
  
  int gamer_score;
  std::string actual_gamer_name;
  std::string time_of_game;
  Snake tSnake;
 
  Gamer *newgamer = new Gamer();
  Snake newsnake;
  newgamer->SetGamerName();
  newgamer->SetGamerGameTime();
  tSnake.head_total_distance = 0;

  Game game(kGridWidth, kGridHeight);
  game.UpdtStartingSpeed();
  
  std::cout << "_________ Let the Game Begin! All the best!! ____________" << std::endl;

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  
  game.Run(controller, renderer, kMsPerFrame);

 
    

    std::cout << "Game has terminated successfully!\n\n";

    std::cout << "----------------------------------- " << std::endl;
    actual_gamer_name = newgamer->GetGamerName();
    std::cout << "Gamer Name :: " << actual_gamer_name << std::endl;
    std::cout << "Game Score :: " << game.GetScore() << "\n";
    gamer_score = game.GetScore();
    std::cout << "Game Size :: " << game.GetSize() << "\n";
    time_of_game = newgamer->GetGamerGameTime();
    std::cout << "Game Time :: " << time_of_game << "\n";
    std::cout << "Snake head total distance :: " << tSnake.head_total_distance << std::endl;
    std::cout << "----------------------------------- " << std::endl;

  return 0;
}