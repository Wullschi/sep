//------------------------------------------------------------------------------
// Quit.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#ifndef QUIT_H_INCLUDED
#define QUIT_H_INCLUDED


#include "Command.h"

class Game;
class Quit : public Command
{
  private:
    //--------------------------------------------------------------------------
    // Private copy constructor
    Quit(const Quit& original);
    //--------------------------------------------------------------------------
    // Private assignment operator
    Quit& operator=(const Quit& original);
    //--------------------------------------------------------------------------
    // Name of this command
    std::string command_name_;
  public:
    //--------------------------------------------------------------------------
    // Constructor
    Quit(std::string name);
    //--------------------------------------------------------------------------
    // Destructor
    virtual ~Quit();
    //--------------------------------------------------------------------------
    // Executes the command.
    // @param board Pointer to the board where action should be performed on
    // @param params Possible parameters needed for the execution
    // @return Status constant  representing the success of the action
    virtual Status execute(Game*& board, std::vector<std::string>& params);
    //--------------------------------------------------------------------------

};


#endif
