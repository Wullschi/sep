//------------------------------------------------------------------------------
// Filename: Load.cpp
// Description: Class representing a general command
// Authors: Tutors
// Tutor: Tutors
// Group: ??
// Created: 02.09.2011
// Last change: 02.09.2011
//------------------------------------------------------------------------------

#include "Load.h"
#include "Game.h"
#include "Loader.h"

//------------------------------------------------------------------------------
Load::Load(std::string name) : Command(name)
{
}
//------------------------------------------------------------------------------
Load::~Load()
{
}
//------------------------------------------------------------------------------


int Load::execute(Game*& board, std::vector<std::string>& params)
{
  
  if (params.size() != 1)
  {
    return 1;
  }
  
  Game* new_board;
  Loader gameloader;
  int load_error = gameloader.load(new_board, params.front());
  
  if (!load_error)
  {
    if (board != 0)
    {
      delete board;
    }
    
    board = new_board;
    std::cout << "LOADED" << std::endl;
    return 0;
  }
  else
  {
    return load_error;
  }
  
}