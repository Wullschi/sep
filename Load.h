//------------------------------------------------------------------------------
// Filename: Load.hpp
// Description: Class representing a general command
// Authors: Tutors
// Tutor: Tutors
// Group: ??
// Created: 08.08.2011
// Last change: 02.09.2011
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
    // @param board The board where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action
    virtual int execute(Game*& board, std::vector<std::string>& params);
    //--------------------------------------------------------------------------
    
};

#endif
