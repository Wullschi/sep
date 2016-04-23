//------------------------------------------------------------------------------
// Filename: Show.h
// Description: Class representing a Show command
// Authors: Tutors
// Tutor: Tutors
// Group: ??
// Created: 08.08.2011
// Last change: 02.09.2011
//------------------------------------------------------------------------------

#ifndef SHOW_H_INCLUDED
#define SHOW_H_INCLUDED

#include "Command.h"

class Show : public Command
{
private:
  //--------------------------------------------------------------------------
  // Private copy constructor
  Show(const Show& original);
  //--------------------------------------------------------------------------
  // Private assignment operator
  Show& operator=(const Show& original);
  //--------------------------------------------------------------------------
public:
  //--------------------------------------------------------------------------
  static const std::string MORE_;
  
  // Constructor
  Show(std::string name);
  //--------------------------------------------------------------------------
  // Destructor
  virtual ~Show();
  //--------------------------------------------------------------------------
  // Executes the command.
  // @param board Pointer to the board where action should be performed on
  // @param params Possible parameters needed for the execution
  // @return Status constant representing the success of the action
  virtual Command::Status execute(Game*& board, std::vector<std::string>& params);
  //--------------------------------------------------------------------------
  
};

#endif