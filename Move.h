//------------------------------------------------------------------------------
// Move.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED


#include "Command.h"


class Game;

//------------------------------------------------------------------------------
// Class representing a move command
//
class Move : public Command
{
  private:
    
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    Move(const Move& original);
    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    Move& operator=(const Move& original);
    
  public:
    
    //--------------------------------------------------------------------------
    // Constants for each of all possible parameters
    //
    static const std::string UP_;
    static const std::string DOWN_;
    static const std::string LEFT_;
    static const std::string RIGHT_;
    
    //--------------------------------------------------------------------------
    // Constructor
    //
    // @param name The name of the command
    //
    Move(std::string name);
    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Move() throw();
    
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
