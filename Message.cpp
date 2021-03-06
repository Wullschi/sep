//------------------------------------------------------------------------------
// Message.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#include "Message.h"

using std::cout;
using std::endl;


const string Message::QUIT_ = "Bye!";
const string Message::CONGRATULATION_ = "Congratulation! You solved the maze.";
const string Message::OUT_OF_MEMORY_ = "[ERR] Out of memory.";
const string Message::WRONG_USAGE_ =
    "[ERR] Wrong usage: ./basic [-s <filename1>] [-m <filename2>]";
const string Message::UNKNOWN_COMMAND_ = "[ERR] Unknown command.";
const string Message::WRONG_PARAMETER_COUNT_ = "[ERR] Wrong parameter count.";
const string Message::WRONG_PARAMETER_ = "[ERR] Wrong parameter.";
const string Message::NO_MAZE_LOADED_ = "[ERR] No maze loaded.";
const string Message::FILE_NOT_OPENED_ = "[ERR] File could not be opened.";
const string Message::INVALID_FILE_ = "[ERR] Invalid file.";
const string Message::INVALID_PATH_ = "[ERR] Invalid path.";
const string Message::FILE_NOT_WRITTEN_ = "[ERR] File could not be written.";
const string Message::INVALID_MOVE_ = "[ERR] Invalid move.";
const string Message::NO_MORE_STEPS_ = "[ERR] No more steps possible.";


//------------------------------------------------------------------------------
void Message::outputWrongUsage()
{
  cout << WRONG_USAGE_ << endl;
}

//------------------------------------------------------------------------------
void Message::outputUnknownCommand()
{
  cout << UNKNOWN_COMMAND_ << endl;
}

//------------------------------------------------------------------------------
void Message::outputByCode(Command::Status return_status)
{
  
  switch (return_status)
  {
      
    case Command::QUIT_:
      cout << QUIT_ << endl;
      break;
      
    case Command::GAME_WON_:
      cout << CONGRATULATION_ << endl;
      break;
      
    case Command::OK_:
      break;
      
    case Command::OUT_OF_MEMORY_:
      cout << OUT_OF_MEMORY_ << endl;
      break;
      
    case Command::WRONG_PARAMETER_COUNT_:
      cout << WRONG_PARAMETER_COUNT_ << endl;
      break;
      
    case Command::WRONG_PARAMETER_:
      cout << WRONG_PARAMETER_ << endl;
      break;
      
    case Command::NO_MAZE_LOADED_:
      cout << NO_MAZE_LOADED_ << endl;
      break;
      
    case Command::FILE_NOT_OPENED_:
      cout << FILE_NOT_OPENED_ << endl;
      break;
      
    case Command::INVALID_FILE_:
      cout << INVALID_FILE_ << endl;
      break;
      
    case Command::INVALID_PATH_:
      cout << INVALID_PATH_ << endl;
      break;
      
    case Command::FILE_NOT_WRITTEN_:
      cout << FILE_NOT_WRITTEN_ << endl;
      break;
      
    case Command::INVALID_MOVE_:
      cout << INVALID_MOVE_ << endl;
      break;
      
    case Command::NO_MORE_STEPS_:
      cout << NO_MORE_STEPS_ << endl;
      break;
      
    
  }
  
}
