//------------------------------------------------------------------------------
// Saver.hpp
//
// Group: Group 13717, study assistant Pascal Nasahl
//
// Authors: <Name> <Matriculum Number>
// <Name> <Matriculum Number>
// <Add one row for every additional group member>
//------------------------------------------------------------------------------
//


#ifndef SAVER_H_INCLUDED
#define SAVER_H_INCLUDED


#include "Filehandler.h"

class Game;
class Saver: public Filehandler
{
  
  private:
    static bool autosave_enabled_;
    static std::string autosave_filename_;
    
    Saver(const Saver &);
  
  public:
    Saver(const std::string filename);
    ~Saver();
    
    int save(const Game& current_game);
    static void enableAutosave(std::string filename);
    static bool isAutosaveActive();
    static std::vector<std::string> getAutosaveParams();
    
};


#endif
