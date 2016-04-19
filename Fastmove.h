//------------------------------------------------------------------------------
// Filename: Fastmove.h
// Description: Class representing a fastmove command
// Authors: Tutors
// Tutor: Tutors
// Group: ??
// Created: 08.08.2011
// Last change: 02.09.2011
//------------------------------------------------------------------------------


#ifndef FASTMOVE_H
#define FASTMOVE_H

#include "Command.h"


class Game;
class Fastmove : public Command
{
  private:
    //--------------------------------------------------------------------------
    // Private copy constructor
    Fastmove(const Fastmove& original);
    //--------------------------------------------------------------------------
    // Private assignment operator
    Fastmove& operator=(const Fastmove& original);
    //--------------------------------------------------------------------------
    
  public:
    //--------------------------------------------------------------------------
    // Constructor
    Fastmove(std::string name);
    //--------------------------------------------------------------------------
    // Destructor
    virtual ~Fastmove();
    //--------------------------------------------------------------------------
    // Executes the command.
    // @param board The board where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action
    virtual int execute(Game*& board, std::vector<std::string>& params);
    //--------------------------------------------------------------------------
  
};

  #endif
  