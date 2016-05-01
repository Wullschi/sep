//------------------------------------------------------------------------------
// Quit.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#include "Quit.h"


#include "Game.h"


//------------------------------------------------------------------------------
Quit::Quit(std::string name) : Command(name)
{
}

//------------------------------------------------------------------------------
Quit::~Quit() throw()
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
  
  return QUIT_;
  
}
