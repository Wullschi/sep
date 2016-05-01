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

//------------------------------------------------------------------------------
// Class for saving a game to a file
// This class also performs the autosave functionality.
//
class Saver : public Filehandler
{
  private:
    
    //--------------------------------------------------------------------------
    // Attribute indicating if the autosave function is enabled
    //
    static bool autosave_enabled_;
    
    //--------------------------------------------------------------------------
    // Attribute for the name of the file to save the maze in
    // in case that autosave is enabled
    //
    static std::string autosave_filename_;
    
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    Saver(const Saver& original);
    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    Saver& operator=(const Saver& original);
    
  public:
    
    //--------------------------------------------------------------------------
    // Constructor
    //
    Saver(const std::string filename);
    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Saver() throw();
    
    Command::Status save(const Game& current_game);
    static void enableAutosave(std::string filename);
    static bool isAutosaveActive();
    static std::vector<std::string> getAutosaveParams();
    
};


#endif
