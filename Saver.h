//------------------------------------------------------------------------------
// Saver.hpp
//
// Group: Group 13717, study assistant Pascal Nasahl
//
// Authors: Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#ifndef SAVER_H_INCLUDED
#define SAVER_H_INCLUDED


#include "Filehandler.h"

class Game;
class Saver : public Filehandler
{
  
  private:
    static bool autosave_enabled_;
    static std::string autosave_filename_;
    
    Saver(const Saver &);
  
  public:
    Saver();
    int save(const Game& CURRENT_GAME, const std::string FILENAME);
    static void enableAutosave(std::string filename);
    
};


#endif