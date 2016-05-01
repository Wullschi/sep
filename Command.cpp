//------------------------------------------------------------------------------
// Command.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#include "Command.h"

//------------------------------------------------------------------------------
Command::Command(std::string name) : command_name_(name)
{
}

//------------------------------------------------------------------------------
Command::~Command() throw()
{
}


//------------------------------------------------------------------------------
const std::string &Command::getName() const
{
  return command_name_;
}
