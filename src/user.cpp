#include <iostream>
#include <string>
#include <ctime>
#include "user.h"

using std::string;

Gamer::Gamer(string gamer_name, int gamer_score, string gamer_gametime)
{
  std::cout << "_______ New Gamer ______ " << std::endl;
  
  this->gamer_name = gamer_name;
  this->gamer_score = gamer_score;
  this->gamer_gametime = gamer_gametime;
  
}

string Gamer::GetGamerName()
{
  return gamer_name;
}

int Gamer::GetGamerScore()
{
  return gamer_score;
}

string Gamer::GetGamerGameTime()
{
  return gamer_gametime;
}


void Gamer::SetGamerName()
{
  string gamer_name;
  std::cout << " Gamer Name : " << gamer_name;
  std::cin >> gamer_name;
  this->gamer_name = gamer_name;
}

void Gamer::SetGamerScore()
{
  int gamer_score;
  //std::cout << " Gamer Score : " << gamer_score;
  //std::cin >> gamer_score;
  this->gamer_score = gamer_score;
}

void Gamer::SetGamerGameTime()
{
  time_t curr = time(0);
  //convert to char
  char* dat = ctime(&curr);
  gamer_gametime = dat;
  std::cout << " Game Time : " << gamer_gametime;
}