//------------------------------------------------------------------------------
// Filename: Fastmove.cpp
// Description: Class representing a Fastmove command
// Authors: Tutors
// Tutor: Tutors
// Group: ??
// Created: 02.09.2011
// Last change: 02.09.2011
//------------------------------------------------------------------------------
#include "Fastmove.h"

#include "Game.h"
#include "Save.h"
#include "Saver.h"

//------------------------------------------------------------------------------
Fastmove::Fastmove(std::string name) : Command(name)
{
}
//------------------------------------------------------------------------------
Fastmove::~Fastmove()
{
}
//------------------------------------------------------------------------------


int Fastmove::execute(Game*& board, std::vector<std::string>& params)
{
  
  if (params.size() != 1)
  {
    std::cout << "Wrong parameter count.\n" << std::endl;
    return 1;
  }
  
  std::string move_sequence = params.front();
  char move_character = '\0';
  for (int character_position = 0; character_position < move_sequence.size(); character_position++)
  {
    move_character = move_sequence[character_position];
    if ( (move_character != 'u') && (move_character != 'd') && (move_character != 'l') && (move_character != 'r') )
    {
      std::cout << "Wrong parameter.\n" << std::endl;
      return 2;
    }
  }
  
  if (board == 0)
  {
    std::cout << "No maze oaded.\n" << std::endl;
    return 3;
  }
  
  int error_code = board->fastMove(move_sequence);
  
  if ( (!error_code) && (Saver::isAutosaveActive()) )
  {
    std::vector<std::string> autosave_params = Saver::getAutosaveParams();
    Save autosave("autosave");
    autosave.execute(board, autosave_params);
  }
  
  return error_code;
  
}
