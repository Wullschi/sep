//------------------------------------------------------------------------------
// Show.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#ifndef SHOW_H_INCLUDED
#define SHOW_H_INCLUDED


#include "Command.h"


//------------------------------------------------------------------------------
// Class representing a show command
//
class Show : public Command
{
  private:
    
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    Show(const Show& original);
    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    Show& operator=(const Show& original);
    
  public:
    
    //--------------------------------------------------------------------------
    // Constant for the more option
    //
    static const std::string MORE_;
    
    //--------------------------------------------------------------------------
    // Constructor
    //
    Show(std::string name);
    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Show() throw();
    
    //--------------------------------------------------------------------------
    // Executes the command.
    // @param board Pointer to the board where action should be performed on
    // @param params Possible parameters needed for the execution
    // @return Status constant representing the success of the action
    //
    virtual Command::Status execute(Game*& board,
        std::vector<std::string>& params);
    
};


#endif
