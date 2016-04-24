//------------------------------------------------------------------------------
// Load.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors:
// Christopher Kopel 0730613
//------------------------------------------------------------------------------

#ifndef LOAD_H
#define LOAD_H

#include "Command.h"


class Game;
class Load : public Command
{
  private:
    //--------------------------------------------------------------------------
    // Private copy constructor
    Load(const Load& original);
    //--------------------------------------------------------------------------
    // Private assignment operator
    Load& operator=(const Load& original);
    //--------------------------------------------------------------------------
    
  public:
    //--------------------------------------------------------------------------
    // Constructor
    Load(std::string name);
    //--------------------------------------------------------------------------
    // Destructor
    virtual ~Load();
    //--------------------------------------------------------------------------
    
    // Executes the command.
    // @param board Pointer to the board where action should be performed on
    // @param params Possible parameters needed for the execution
    // @return Status constant  representing the success of the action
    virtual Command::Status execute(Game*& board,
    std::vector<std::string>& params);
    //--------------------------------------------------------------------------
    
};

#endif
