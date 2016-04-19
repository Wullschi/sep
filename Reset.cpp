//------------------------------------------------------------------------------
// Filename: Reset.cpp
// Description: Class representing a Reset command
// Authors: Tutors
// Tutor: Tutors
// Group: ??
// Created: 02.09.2011
// Last change: 02.09.2011
//------------------------------------------------------------------------------

#include "Reset.h"

#include "Game.h"
#include "Saver.h"
#include "Save.h"


//------------------------------------------------------------------------------
Reset::Reset(std::string name) : Command(name)
{
}
//------------------------------------------------------------------------------
Reset::~Reset()
{
}
//------------------------------------------------------------------------------

int Reset::execute(Game*& board, std::vector<std::string>& params)
{
  
  if (params.size())
  {
    std::cout << "Wrong parameter count.\n" << std::endl;
    return 1;
  }
  
  if (!board)
  {
    std::cout << "No maze loaded.\n" << std::endl;
    return 3;
  }
  
  board->reset();
  
  if (Saver::isAutosaveActive())
  {
    std::vector<std::string> autosave_params = Saver::getAutosaveParams();
    Save autosave("autosave");
    autosave.execute(board, autosave_params);
  }
  
  return 0;
  
}
