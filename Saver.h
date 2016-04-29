//------------------------------------------------------------------------------
// Saver.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#ifndef SAVER_H_INCLUDED
#define SAVER_H_INCLUDED


#include "Filehandler.h"

#include "Command.h"   // necessary to access Command Status constants

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
    
    Command::Status save(const Game& current_game);
    static void enableAutosave(std::string filename);
    static bool isAutosaveActive();
    static std::vector<std::string> getAutosaveParams();
    
};


#endif
