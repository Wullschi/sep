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


//------------------------------------------------------------------------------
Move::Move(std::string name) : Command(name)
{
}

//------------------------------------------------------------------------------

Move::~Move()
{
}

//------------------------------------------------------------------------------

int Move::execute(Game*& board, std::vector<std::string>& params)
{
  
  if (params.size() != 1)
  {
    std::cout << "Wrong parameter count.\n" << std::endl;
    return 1;
  }
  
  if ( (params.front() != "up") && (params.front() != "down")
    && (params.front() != "left") && (params.front() != "right") )
  {
    std::cout << "Wrong parameter.\n" << std::endl;
    return 2;
  }
  
  if (board == 0)
  {
    std::cout << "No maze loaded.\n" << std::endl;
    return 3;
  }
  
  board->move(params.front());
  
  return 0;
}
