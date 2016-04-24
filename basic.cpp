//------------------------------------------------------------------------------
// basic.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors:
// Christopher Kopel 0730613
//------------------------------------------------------------------------------



#include "Game.h"
#include "UserInput.h"
#include "Coordinates.h"



int main(int argc, const char* argv[])
{
  
  Game* current_game = 0;
  
  int error_code = UserInput::checkCommandLineOptions(argc, argv, current_game);
  
  if (error_code)
  {
    return error_code;
  }
  
  
  error_code = UserInput::commandLine(current_game);
  
  if (error_code == 1)
  {
    delete current_game;
    return error_code;
  }
  else
  {
    return 0;
  }
  
}
