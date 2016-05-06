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
    // for the case that autosave is enabled
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
    // @param filename The name of the file to save in
    //
    Saver(const std::string filename);
    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Saver() throw();
    
    //--------------------------------------------------------------------------
    // Saves a board, the naximum number of steps
    // allowed for this board, and the steps already done by the
    // player into the text file specified in filename_.
    //
    // @param current_game The board to save
    //
    // @return Constant of type Status (defined in class Command)
    //         representing the success of the action
    //
    Command::Status save(const Game& current_game);
    
    //--------------------------------------------------------------------------
    // Activates the autosave functionality by setting autosave_enabled_
    // to true and storing the parameter to autosave_filename_.
    // If autosave is activated, the game currently loaded
    // is saved to the file specified by autosave_filename_
    // after every successful action (valid move, reset etc.).
    //
    // @param filename The name of the file to automatically save in
    //
    static void enableAutosave(std::string filename);
    
    //--------------------------------------------------------------------------
    // Returns the value of autosave_enabled_.
    //
    // @return True if autosave is activated, false if not.
    //
    static bool isAutosaveActive();
    
    //--------------------------------------------------------------------------
    // Returns the value of autosave_filename_.
    //
    // @return Vector with one string element containing the filename to
    //         automatically save the current game in
    //         (empty string if autosave is not activated)
    //
    static std::vector<std::string> getAutosaveParams();
    
};


#endif
