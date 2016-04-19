//------------------------------------------------------------------------------
// Saver.cpp
//
// Group: Group 13717, study assistant Pascal Nasahl
//
// Authors: <Name> <Matriculum Number>
// <Name> <Matriculum Number>
// <Add one row for every additional group member>
//------------------------------------------------------------------------------
//


#include <vector>
#include <fstream>

#include "Saver.h"
#include "Game.h"
#include "Field.h"


bool Saver::autosave_enabled_ = false;
std::string Saver::autosave_filename_ = "";

Saver::Saver()
{
  
}


int Saver::save(const Game& CURRENT_GAME, const std::string FILENAME)
{
  
  
  
  const char* SAVEFILE = FILENAME.c_str();
  
  std::ofstream file(SAVEFILE);
  if (!file.is_open())
  {
    std::cout << "cannot open file" << std::endl;
  }
  else
  {
    
    file << CURRENT_GAME.getFinishedTurns() << "\n";
    file << CURRENT_GAME.getMaxTurns() << "\n";
    
    const std::vector<std::vector<Field*> > board = CURRENT_GAME.getBoard();
    
    for (unsigned int y = 0; y < board.size(); y++)
    {
      for (unsigned int x = 0; x < board[y].size(); x++)
      {
        
        file << board[y][x]->getFieldSymbol();
      }

      file << "\n";
    }
    
    
    file.close();
  }
   
  return 0;

}
  

void Saver::enableAutosave(std::string filename)
{
  autosave_enabled_ = true;
  autosave_filename_ = filename;
  
}

bool Saver::isAutosaveActive()
{
  return Saver::autosave_enabled_;
}

std::vector<std::string> Saver::getAutosaveParams()
{
  std::vector<std::string> autosave_params;
  autosave_params.push_back(Saver::autosave_filename_);
  return autosave_params;
}
