//------------------------------------------------------------------------------
// Fastmove.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#include "Fastmove.h"

#include "Game.h"
#include "Save.h"
#include "Saver.h"
#include "Show.h"
#include "Reset.h"
#include "UserInput.h"
#include "Message.h"


const std::string Fastmove::VALID_PARAMETERS_ = "ldru";
const std::string Fastmove::UP_ = "u";
const std::string Fastmove::DOWN_ = "d";
const std::string Fastmove::LEFT_ = "l";
const std::string Fastmove::RIGHT_ = "r";


//------------------------------------------------------------------------------
Fastmove::Fastmove(std::string name) : Command(name)
{
}
//------------------------------------------------------------------------------
Fastmove::~Fastmove() throw()
{
}
//------------------------------------------------------------------------------


Command::Status Fastmove::execute(Game*& board,
    std::vector<std::string>& params)
{
  
  if (params.size() != 1)
  {
    return WRONG_PARAMETER_COUNT_;
  }
  
  if (params.front().find_first_not_of(VALID_PARAMETERS_) != std::string::npos)
  {
    return WRONG_PARAMETER_;
  }
  
  if (!board)
  {
    return NO_MAZE_LOADED_;
  }
  
  Command::Status return_status = board->fastMove(params.front());
  
  if (return_status <= 0)
  {
    
    if (Saver::isAutosaveActive())
    {
      std::vector<std::string> autosave_params = Saver::getAutosaveParams();
      Save autosave("autosave");
      Command::Status autosave_status
          = autosave.execute(board, autosave_params);
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
