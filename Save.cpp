//------------------------------------------------------------------------------
// Filename: Save.cpp
// Description: Class representing a Save  command
// Authors: Tutors
// Tutor: Tutors
// Group: ??
// Created: 02.09.2011
// Last change: 02.09.2011
//------------------------------------------------------------------------------

#include "Save.h"
#include "Game.h"
#include "Saver.h"

//------------------------------------------------------------------------------
Save::Save(std::string name) : Command(name)
{
}
//------------------------------------------------------------------------------
Save::~Save()
{
}
//------------------------------------------------------------------------------


Command::Status Save::execute(Game*& board, std::vector<std::string>& params)
{
  
  if (params.size() != 1)
  {
    std::cout << "Wrong parameter count.\n" << std::endl;
    return WRONG_PARAMETER_COUNT;
  }
  
  Saver gamesaver(params.front());
  
  if (!gamesaver.filenameIsValid())
  {
    std::cout << "Wrong parameter.\n" << std::endl;
    return WRONG_PARAMETER;
  }
  
  if (!board)
  {
    std::cout << "No maze loaded.\n" << std::endl;
    return NO_MAZE_LOADED;
  }
  
  Command::Status return_status = gamesaver.save(*board);
  
  return return_status;
  
}
