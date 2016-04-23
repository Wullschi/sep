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
    return WRONG_PARAMETER_COUNT_;
  }
  
  Saver gamesaver(params.front());
  
  if (!gamesaver.filenameIsValid())
  {
    return WRONG_PARAMETER_;
  }
  
  if (!board)
  {
    return NO_MAZE_LOADED_;
  }
  
  Command::Status return_status = gamesaver.save(*board);
  
  return return_status;
  
}
