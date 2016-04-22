//------------------------------------------------------------------------------
// Filename: Move.cpp
// Description: Class representing a move command
// Authors: Tutors
// Tutor: Tutors
// Group: ??
// Created: 02.09.2011
// Last change: 02.09.2011
//------------------------------------------------------------------------------


#include "Move.h"

#include "Game.h"
#include "Save.h"
#include "Saver.h"
#include "Show.h"
#include "UserInput.h"


//------------------------------------------------------------------------------
Move::Move(std::string name) : Command(name)
{
}

//------------------------------------------------------------------------------

Move::~Move()
{
}

//------------------------------------------------------------------------------

Command::Status Move::execute(Game*& board, std::vector<std::string>& params)
{
  
  if (params.size() != 1)
  {
    std::cout << "Wrong parameter count.\n" << std::endl;
    return WRONG_PARAMETER_COUNT;
  }
  
  std::string parameter = params.front();
  if ( (parameter != "up") && (parameter != "down")
      && (parameter != "left") && (parameter != "right") )
  {
    std::cout << "Wrong parameter.\n" << std::endl;
    return WRONG_PARAMETER;
  }
  
  if (board == 0)
  {
    std::cout << "No maze loaded.\n" << std::endl;
    return NO_MAZE_LOADED;
  }
  
  Command::Status return_status = board->move(parameter);
  
  if (!return_status)
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
