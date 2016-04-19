//------------------------------------------------------------------------------
// Filename: Move.h
// Description: Class representing a move command
// Authors: Tutors
// Tutor: Tutors
// Group: ??
// Created: 08.08.2011
// Last change: 02.09.2011
//------------------------------------------------------------------------------
#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

#include "Command.h"


class Game;
class Move : public Command
{
  private:
    //--------------------------------------------------------------------------
    // Private copy constructor
    Move(const Move& original);
    //--------------------------------------------------------------------------
    // Private assignment operator
    Move& operator=(const Move& original);
    //--------------------------------------------------------------------------
    
  public:
  //--------------------------------------------------------------------------
    // Constructor
    Move(std::string name);
    //--------------------------------------------------------------------------
    // Destructor
    virtual ~Move();
    //--------------------------------------------------------------------------
    // Executes the command.
    // @param board The board where action should be performed on
    // @param params Possible parameters neede for the execution
    // @return Integer representing the success of the action
    virtual int execute(Game*& board, std::vector<std::string>& params);
    //--------------------------------------------------------------------------

};

  #endif