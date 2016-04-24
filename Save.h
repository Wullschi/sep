//------------------------------------------------------------------------------
// Save.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors:
// Christopher Kopel 0730613
//------------------------------------------------------------------------------

#ifndef SAVE_H
#define SAVE_H

#include "Command.h"


class Game;
class Save : public Command
{
  private:
    //--------------------------------------------------------------------------
    // Private copy constructor
    Save(const Save& original);
    //--------------------------------------------------------------------------
    // Private assignment operator
    Save& operator=(const Save& original);
    //--------------------------------------------------------------------------
    
  public:
    //--------------------------------------------------------------------------
    // Constructor
    Save(std::string name);
    //--------------------------------------------------------------------------
    // Destructor
    virtual ~Save();
    //--------------------------------------------------------------------------
    
    // Executes the command.
    // @param board Pointer to the board where action should be performed on
    // @param params Possible parameters needed for the execution
    // @return Status constant representing the success of the action
    virtual Command::Status execute(Game*& board, std::vector<std::string>& params);
    //--------------------------------------------------------------------------
    
};

#endif
