//------------------------------------------------------------------------------
// Filename: Show.cpp
// Description: Class representing a Show command
// Authors: Tutors
// Tutor: Tutors
// Group: ??
// Created: 02.09.2011
// Last change: 02.09.2011
//------------------------------------------------------------------------------

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
  
  else if (params.size() > 1)
  {
    return WRONG_PARAMETER_COUNT_;
  }
  
  if (!board)
  {
    return NO_MAZE_LOADED_;
  }
  
  board->show(more);
  
  return OK_;
  
}
