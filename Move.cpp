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
#include "Reset.h"
#include "UserInput.h"
#include "Message.h"


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
    return WRONG_PARAMETER_COUNT_;
  }
  
  std::string parameter = params.front();
  if ( (parameter != "up") && (parameter != "down")
      && (parameter != "left") && (parameter != "right") )
  {
    return WRONG_PARAMETER_;
  }
  
  if (board == 0)
  {
    return NO_MAZE_LOADED_;
  }
  
  Command::Status return_status = board->move(parameter);
  
  if (return_status <= 0)
  {
    
    if (Saver::isAutosaveActive())
    {
      std::vector<std::string> autosave_params = Saver::getAutosaveParams();
      Save autosave("autosave");
      Command::Status autosave_status = autosave.execute(board, autosave_params);
      if (autosave_status)
      {
        Message::outputByCode(autosave_status);
      }
    }
    
    Show implicit_show("implicit_show");
    std::vector<std::string> show_params;
    implicit_show.execute(board, show_params);
    
  }
  else if (return_status == NO_MORE_STEPS_)
  {
    std::vector<std::string> reset_params;
    Reset auto_reset("auto_reset");
    auto_reset.execute(board, reset_params);
  }
  
  return return_status;
  
}
