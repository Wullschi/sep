//------------------------------------------------------------------------------
// Filename: Save.h
// Description: Class representing a Save  command
// Authors: Tutors
// Tutor: Tutors
// Group: ??
// Created: 08.08.2011
// Last change: 02.09.2011
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
    // @param board The board where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action
    virtual int execute(Game*& board, std::vector<std::string>& params);
    //--------------------------------------------------------------------------
    
};

#endif
