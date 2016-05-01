//------------------------------------------------------------------------------
// Saver.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#include <fstream>

#include "Saver.h"

#include "Game.h"
#include "Field.h"


bool Saver::autosave_enabled_ = false;
std::string Saver::autosave_filename_ = "";

//------------------------------------------------------------------------------
Saver::Saver(const std::string filename) : Filehandler(filename)
{
}

//------------------------------------------------------------------------------
Saver::~Saver() throw()
{
}


//------------------------------------------------------------------------------
Command::Status Saver::save(const Game& current_game)
{
  
  const char* SAVEFILE = filename_.c_str();
  
  std::ofstream file(SAVEFILE);
  if (!file.is_open())
  {
    return Command::FILE_NOT_WRITTEN_;
  }
  else
  {
    
    file << current_game.getFinishedTurns() << "\n";
    file << current_game.getMaxTurns() << "\n";
    
    const std::vector<std::vector<Field*> >* board = current_game.getBoard();
    
    for (unsigned int y = 0; y < board->size(); y++)
    {
      for (unsigned int x = 0; x < board->at(y).size(); x++)
      {
        
        file << board->at(y).at(x)->getFieldSymbol(Field::FOR_SAVING);
      }

      file << "\n";
    }
    
    
    file.close();
  }
   
  return Command::OK_;

}
  

//------------------------------------------------------------------------------
void Saver::enableAutosave(std::string filename)
{
  autosave_enabled_ = true;
  autosave_filename_ = filename;
}


//------------------------------------------------------------------------------
bool Saver::isAutosaveActive()
{
  return Saver::autosave_enabled_;
}


//------------------------------------------------------------------------------
std::vector<std::string> Saver::getAutosaveParams()
{
  std::vector<std::string> autosave_params;
  autosave_params.push_back(Saver::autosave_filename_);
  return autosave_params;
}
