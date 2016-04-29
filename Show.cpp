//------------------------------------------------------------------------------
// Show.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#include "Show.h"

#include "Game.h"


const std::string Show::MORE_ = "more";


//------------------------------------------------------------------------------
Show::Show(std::string name) : Command(name)
{
}
//------------------------------------------------------------------------------
Show::~Show()
{
}
//------------------------------------------------------------------------------

Command::Status Show::execute(Game*& board, std::vector<std::string>& params)
{
  
  bool more = false;
  
  if (params.size() > 1)
  {
    return WRONG_PARAMETER_COUNT_;
  }
  
  if (params.size() == 1)
  {
    if (params.front() == MORE_)
	{
      more = true;
    }
    else
    {
      return WRONG_PARAMETER_;
    }
  }
  
  
  if (!board)
  {
    return NO_MAZE_LOADED_;
  }
  
  board->show(more);
  
  return OK_;
  
}
