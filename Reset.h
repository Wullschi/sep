//------------------------------------------------------------------------------
// Filename: Reset.h
// Description: Class representing a Reset command
// Authors: Tutors
// Tutor: Tutors
// Group: ??
// Created: 08.08.2011
// Last change: 02.09.2011
//------------------------------------------------------------------------------
#ifndef RESET_H
#define RESET_H

#include "Command.h"


class Game;
class Reset : public Command
{
  private:
    //--------------------------------------------------------------------------
    // Private copy constructor
    Reset(const Reset& original);
    //--------------------------------------------------------------------------
    // Private assignment operator
    Reset& operator=(const Reset& original);
    //--------------------------------------------------------------------------
    
  public:
    //--------------------------------------------------------------------------
    // Constructor
    Reset(std::string name);
    //--------------------------------------------------------------------------
    // Destructor
    virtual ~Reset();
    //--------------------------------------------------------------------------
    
    // Executes the command.
    // @param board Pointer to the board where action should be performed on
    // @param params Possible parameters needed for the execution
    // @return Status constant  representing the success of the action
    virtual Command::Status execute(Game*& board, std::vector<std::string>& params);
    //--------------------------------------------------------------------------
    
};

#endif
