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
#include "Show.h"

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
    std::cout << "Wrong parameter count.\n" << std::endl;
    return 1;
  }
  
  Game* new_board = 0;
  Loader gameloader(params.front());
  
  if (!gameloader.filenameIsValid())
  {
    std::cout << "Wrong parameter.\n" << std::endl;
    return 2;
  }
  
  int load_error = gameloader.load(new_board);
  
  if (!load_error)
  {
    if (board != 0)
    {
      delete board;
    }
    
    board = new_board;
    
    Show implicit_show("implicit_show");
    std::vector<std::string> show_params;
    implicit_show.execute(board, show_params);
    
  }
  
  return load_error;
  
}
