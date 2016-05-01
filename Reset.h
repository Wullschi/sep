//------------------------------------------------------------------------------
// Reset.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#ifndef RESET_H_INCLUDED
#define RESET_H_INCLUDED


#include "Command.h"


class Game;

//------------------------------------------------------------------------------
// Class representing a reset command
//
class Reset : public Command
{
  private:
    
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    Reset(const Reset& original);
    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    Reset& operator=(const Reset& original);
    
  public:
    
    //--------------------------------------------------------------------------
    // Constructor
    //
    Reset(std::string name);
    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Reset() throw();
    
    //--------------------------------------------------------------------------
    // Executes the command.
    // @param board Pointer to the board where action should be performed on
    // @param params Possible parameters needed for the execution
    // @return Status constant  representing the success of the action
    //
    virtual Command::Status execute(Game*& board,
        std::vector<std::string>& params);
    
};


#endif
