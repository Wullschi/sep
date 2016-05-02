//------------------------------------------------------------------------------
// Command.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED


#include <iostream>
#include <string>
#include <vector>


class Game;

//------------------------------------------------------------------------------
// Abstract class representing a general command
//
class Command
{
  private:
    
    //--------------------------------------------------------------------------
    // Name of this command
    //
    std::string command_name_;
    
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    Command(const Command& original);
    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    Command& operator=(const Command& original);
    
  public:
    
    //--------------------------------------------------------------------------
    // Constant type for all possible return values
    // of the execute methods of the commands
    //
    enum Status
    {
      QUIT_ = -2,
      GAME_WON_ = -1,
      OK_,
      OUT_OF_MEMORY_,
      WRONG_PARAMETER_COUNT_,
      WRONG_PARAMETER_,
      NO_MAZE_LOADED_,
      FILE_NOT_OPENED_,
      INVALID_FILE_,
      INVALID_PATH_,
      FILE_NOT_WRITTEN_,
      INVALID_MOVE_,
      NO_MORE_STEPS_
    };
    
    //--------------------------------------------------------------------------
    // Constructor
    //
    Command(std::string name);
    //--------------------------------------------------------------------------
    // Destructor
    //
    virtual ~Command() throw();
    
    //--------------------------------------------------------------------------
    // Executes the command.
    // @param board Pointer to the board where action should be performed on
    // @param params Possible parameters needed for the execution
    // @return Status constant  representing the success of the action
    //
    virtual Status execute(Game*& board, std::vector<std::string>& params) = 0;
    
    //--------------------------------------------------------------------------
    // Getter Methods
    //
    const std::string& getName() const;
    
};


#endif
