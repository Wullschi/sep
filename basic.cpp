//------------------------------------------------------------------------------
// basic.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#include "Game.h"
#include "UserInput.h"
#include "Message.h"


//------------------------------------------------------------------------------
// Main function
// entry point of execution
//
int main(int argc, const char* argv[])
{
  
  Game* current_game = 0;
  
  int error_code = UserInput::checkCommandLineOptions(argc, argv, current_game);
  
  if (error_code)
  {
    Message::outputWrongUsage();
    return error_code;
  }
  
  
  error_code = UserInput::commandLine(current_game);
  
  if (error_code)
  {
    delete current_game;
    current_game = 0;
  }
  
  return error_code;
  
}
