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


int Save::execute(Game*& board, std::vector<std::string>& params)
{
  
  if (params.size() != 1)
  {
    std::cout << "Wrong parameter count.\n" << std::endl;
    return 1;
  }
  
  if (!board)
  {
    std::cout << "No maze loaded.\n" << std::endl;
    return 3;
  }
  
  Saver gamesaver;
  int save_error = gamesaver.save(*board, params.front());
  
  return save_error;
  
}
