//------------------------------------------------------------------------------
// Fastmove.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors:
// Christopher Kopel 0730613
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
    static const std::string VALID_COMMANDS_;
    static const std::string UP_;
    static const std::string DOWN_;
    static const std::string LEFT_;
    static const std::string RIGHT_;
    
    // Constructor
    Fastmove(std::string name);
    //--------------------------------------------------------------------------
    // Destructor
    virtual ~Fastmove();
    //--------------------------------------------------------------------------
    // Executes the command.
    // @param board Pointer to the board where action should be performed on
    // @param params Possible parameters needed for the execution
    // @return Status constant representing the success of the action
    virtual Command::Status execute(Game*& board,
        std::vector<std::string>& params);
    //--------------------------------------------------------------------------
  
};

  #endif
  