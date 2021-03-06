//------------------------------------------------------------------------------
// Move.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#include "Move.h"


#include "Game.h"
#include "Save.h"
#include "Saver.h"
#include "Show.h"
#include "Reset.h"
#include "UserInput.h"
#include "Message.h"


const std::string Move::UP_ = "up";
const std::string Move::DOWN_ = "down";
const std::string Move::LEFT_ = "left";
const std::string Move::RIGHT_ = "right";


//------------------------------------------------------------------------------
Move::Move(std::string name) : Command(name)
{
}

//------------------------------------------------------------------------------
Move::~Move() throw()
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
  if ( (parameter != UP_) && (parameter != DOWN_)
      && (parameter != LEFT_) && (parameter != RIGHT_) )
  {
    return WRONG_PARAMETER_;
  }
  
  if (board == 0)
  {
    return NO_MAZE_LOADED_;
  }
  
  Command::Status return_status = board->move(parameter);
  
  if (return_status == NO_MORE_STEPS_)
  {
    std::vector<std::string> reset_params;
    Reset auto_reset("auto_reset");
    auto_reset.execute(board, reset_params);
  }
  
  if (return_status > 0)
  {
    return return_status;
  }
  
  if (Saver::isAutosaveActive())
  {
    
    std::vector<std::string> autosave_params = Saver::getAutosaveParams();
    Save autosave("autosave");
    Command::Status autosave_status =
        autosave.execute(board, autosave_params);
      
    if (autosave_status)
    {
      Message::outputByCode(autosave_status);
    }
    
  }
  
  Show implicit_show("implicit_show");
  std::vector<std::string> show_params;
  implicit_show.execute(board, show_params);
  
  return return_status;
  
}
