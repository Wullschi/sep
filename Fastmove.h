//------------------------------------------------------------------------------
// Fastmove.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#ifndef FASTMOVE_H_INCLUDED
#define FASTMOVE_H_INCLUDED


#include "Command.h"


class Game;

//------------------------------------------------------------------------------
// Class representing the fastmove command
//
class Fastmove : public Command
{
  private:
    
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    Fastmove(const Fastmove& original);
    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    Fastmove& operator=(const Fastmove& original);
    
  public:
    
    //--------------------------------------------------------------------------
    // Constant containing all valid parameters
    //
    static const std::string VALID_PARAMETERS_;
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
    Fastmove(std::string name);
    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Fastmove() throw();
    
    //--------------------------------------------------------------------------
    // Executes the command.
    //
    // @param board Pointer to the board where action should be performed on
    // @param params Possible parameters needed for the execution
    //
    // @return Status constant representing the success of the action
    //
    virtual Command::Status execute(Game*& board,
        std::vector<std::string>& params);
    
};


#endif
