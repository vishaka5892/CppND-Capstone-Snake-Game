#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include "snake.h"

using std::string;

class Gamer {
public: 
  Gamer() {std::cout << "__________ New Gamer _________ " << std::endl;}
  Gamer(string, int, string);
  ~Gamer() {}
  Snake newSnake();
  
  string GetGamerName();
  int GetGamerScore();
  string GetGamerGameTime();
  
  void SetGamerName();
  void SetGamerScore();
  void SetGamerGameTime();
  
private:
  string gamer_name;
  int gamer_score;
  string gamer_gametime;
  
};
 
#endif