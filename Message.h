//------------------------------------------------------------------------------
// Message.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED


#include <string>

#include "Command.h"   // necessary to access Status constants

using std::string;


class Message
{
  private:
    
    Message();
    
    static const string QUIT_;
    static const string CONGRATULATION_;
    static const string OUT_OF_MEMORY_;
    static const string WRONG_USAGE_;
    static const string UNKNOWN_COMMAND_;
    static const string WRONG_PARAMETER_COUNT_;
    static const string WRONG_PARAMETER_;
    static const string NO_MAZE_LOADED_;
    static const string FILE_NOT_OPENED_;
    static const string INVALID_FILE_;
    static const string INVALID_PATH_;
    static const string FILE_NOT_WRITTEN_;
    static const string INVALID_MOVE_;
    static const string NO_MORE_STEPS_;
    
  public:
    
    static void outputWrongUsage();
    static void outputUnknownCommand();
    static void outputByCode(Command::Status return_status);
    
};


#endif
