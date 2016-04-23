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
#include "Message.h"


//------------------------------------------------------------------------------
Reset::Reset(std::string name) : Command(name)
{
}
//------------------------------------------------------------------------------
Reset::~Reset()
{
}
//------------------------------------------------------------------------------

Command::Status Reset::execute(Game*& board, std::vector<std::string>& params)
{
  
  if (params.size())
  {
    return WRONG_PARAMETER_COUNT_;
  }
  
  if (!board)
  {
    return NO_MAZE_LOADED_;
  }
  
  board->reset();
  
  if (Saver::isAutosaveActive())
  {
    std::vector<std::string> autosave_params = Saver::getAutosaveParams();
    Save autosave("autosave");
    Command::Status autosave_status = autosave.execute(board, autosave_params);
    if (autosave_status)
      {
        Message::outputByCode(autosave_status);
      }
    }
  
  return OK_;
  
}
