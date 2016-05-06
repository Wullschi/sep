//------------------------------------------------------------------------------
// Load.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#ifndef LOAD_H_INCLUDED
#define LOAD_H_INCLUDED


#include "Command.h"


class Game;

//------------------------------------------------------------------------------
// Class representing a load command
//
class Load : public Command
{
  private:
    
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    Load(const Load& original);
    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    Load& operator=(const Load& original);
    
  public:
    
    //--------------------------------------------------------------------------
    //--------------------------------------------------------------------------
    // Constructor
    //
    // @param name The name of the command
    //
    Load(std::string name);
    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Load() throw();
    
    //--------------------------------------------------------------------------
    // Executes the command.
    //
    // @param board Pointer to the board where action should be performed on
    // @param params Possible parameters needed for the execution
    //
    // @return Status constant  representing the success of the action
    //
    virtual Command::Status execute(Game*& board,
        std::vector<std::string>& params);
    
};


#endif
