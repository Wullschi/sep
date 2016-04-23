//------------------------------------------------------------------------------
// UserInput.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors:
// Christopher Kopel 0730613
//------------------------------------------------------------------------------

#include "Fastmove.h"

#include "Game.h"
#include "Save.h"
#include "Saver.h"
#include "Show.h"
#include "UserInput.h"


//------------------------------------------------------------------------------
Fastmove::Fastmove(std::string name) : Command(name)
{
}
//------------------------------------------------------------------------------
Fastmove::~Fastmove()
{
}
//------------------------------------------------------------------------------


Command::Status Fastmove::execute(Game*& board,
    std::vector<std::string>& params)
{
  
  if (params.size() != 1)
  {
    std::cout << "Wrong parameter count.\n" << std::endl;
    return WRONG_PARAMETER_COUNT;
  }
  
  if (params.front().find_first_not_of("ldru") != std::string::npos)
  {
    std::cout << params.front() << std::endl;
    std::cout << "Wrong parameter.\n" << std::endl;
    return WRONG_PARAMETER;
  }
  
  if (board == 0)
  {
    std::cout << "No maze added.\n" << std::endl;
    return NO_MAZE_LOADED;
  }
  
  Command::Status return_status = board->fastMove(params.front());
  
  if (return_status <= 0)
  {
    
    if (Saver::isAutosaveActive())
    {
      std::vector<std::string> autosave_params = Saver::getAutosaveParams();
      Save autosave("autosave");
      autosave.execute(board, autosave_params);
    }
    
    Show implicit_show("implicit_show");
    std::vector<std::string> show_params;
    implicit_show.execute(board, show_params);
    
  }
  
  if (return_status == GAME_WON)
  {
    std::cout << UserInput::CONGRATULATION_MESSAGE_ << std::endl;
  }
    
  return return_status;
  
}
