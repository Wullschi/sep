//------------------------------------------------------------------------------
// Filename: Command.h
// Description: Class representing a quit command
// Authors: Tutors
// Tutor: Tutors
// Group: ??
// Created: 08.08.2011
// Last change: 02.09.2011
//------------------------------------------------------------------------------
#ifndef QUIT_H_INCLUDED
#define QUIT_H_INCLUDED

#include "Command.h"

class Game;
class Quit : public Command
{
private:
  //--------------------------------------------------------------------------
  // Private copy constructor
  Quit(const Quit& original);
  //--------------------------------------------------------------------------
  // Private assignment operator
  Quit& operator=(const Quit& original);
  //--------------------------------------------------------------------------
  /// Name of this command
  std::string command_name_;
public:
  //--------------------------------------------------------------------------
  // Constructor
  Quit(std::string name);
  //--------------------------------------------------------------------------
  // Destructor
  virtual ~Quit();
  //--------------------------------------------------------------------------
  // Executes the command.
  // @param board Pointer to the board where action should be performed on
  // @param params Possible parameters needed for the execution
  // @return Status constant  representing the success of the action
  virtual Status execute(Game*& board, std::vector<std::string>& params);
  //--------------------------------------------------------------------------

};

#endif