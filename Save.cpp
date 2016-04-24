//------------------------------------------------------------------------------
// Save.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors:
// Christopher Kopel 0730613
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
