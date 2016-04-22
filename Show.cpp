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
    if (params.front() == "more")
    {
      more = true;
    }
    else
    {
      std::cout << "Wrong parameter.\n" << std::endl;
      return WRONG_PARAMETER;
    }
  
  }
  
  else if (params.size() > 1)
  {
    std::cout << "Wrong parameter count.\n" << std::endl;
    return WRONG_PARAMETER_COUNT;
  }
  
  if (!board)
  {
    std::cout << "No maze loaded.\n" << std::endl;
    return NO_MAZE_LOADED;
  }
  
  board->show(more);
  
  return OK;
  
}
