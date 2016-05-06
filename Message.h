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


//------------------------------------------------------------------------------
// Singleton class providing constants for all possible messages
// and methods for outputting them
//
class Message
{
  private:
    
    //------------------------------------------------------------------------------
    // Private constructor (because this is a singleton class)
    //
    Message();
    
    //------------------------------------------------------------------------------
    // Constants for all possible screen messages
    //
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
    
    //--------------------------------------------------------------------------
    // Prints the message stored in WRONG_USAGE_ onto the screen.
    //
    static void outputWrongUsage();
    
    //--------------------------------------------------------------------------
    // Prints the message stored in UNKNOWN_COMMAND_ onto the screen.
    //
    static void outputUnknownCommand();
    
    //--------------------------------------------------------------------------
    // Prints an appropriate message onto the screen
    // for the case specified by the parameter.
    //
    // @param return_status Constant of type Status (defined in class Command)
    //        specifying the case for which to print a message
    //
    static void outputByCode(Command::Status return_status);
    
};


#endif
