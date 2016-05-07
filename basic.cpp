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
  
  int error_code;
  try
  {
    error_code = UserInput::checkCommandLineOptions(argc, argv, current_game);
  }
  catch (std::bad_alloc& exception)
  {
    error_code = Command::OUT_OF_MEMORY_;
  }
  
  if (error_code == UserInput::WRONG_USAGE_RETURN_)
  {
    Message::outputWrongUsage();
  }
  
  if (error_code == UserInput::OK_)
  {
    try
    {
      error_code = UserInput::commandLine(current_game);
    }
    catch (std::bad_alloc& exception)
    {
      error_code = Command::OUT_OF_MEMORY_;
    }
  }
  
  if (current_game)
  {
    delete current_game;
    current_game = 0;
  }
  
  return error_code;
  
}
