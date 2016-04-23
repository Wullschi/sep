//------------------------------------------------------------------------------
// Filename: Quit.cpp
// Description: Class representing a Quit command
// Authors: Tutors
// Tutor: Tutors
// Group: ??
// Created: 02.09.2011
// Last change: 02.09.2011
//------------------------------------------------------------------------------

#include "Quit.h"

#include "Game.h"
#include "Message.h"


//------------------------------------------------------------------------------
Quit::Quit(std::string name) : Command(name)
{
}
//------------------------------------------------------------------------------
Quit::~Quit()
{
}
//------------------------------------------------------------------------------

Command::Status Quit::execute(Game*& board, std::vector<std::string>& params)
{
  
  if (params.size())
  {
    return WRONG_PARAMETER_COUNT_;
  }
  
  if (board)
  {
    delete board;
    board = 0;
  }
  
  Message::outputQuit();
    
  return OK_;
  
}
