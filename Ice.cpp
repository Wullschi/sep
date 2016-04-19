//------------------------------------------------------------------------------
// ice.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------
//
#include "Ice.h"

/****************************************************************************
 *                      Constructor und Destructor                          *
 ****************************************************************************/

Ice::Ice(int x, int y) : Field(x, y)
{
  field_symbol_ = "+";
}

Ice::~Ice( ){
  std::cout << "Field x: " << x_var_ << "   y:  " << y_var_ << " has been deleted" <<std::endl;
}

/****************************************************************************
 *                          Restliche Funktionen                            *
 ****************************************************************************/

int Ice::enter(std::string enter_from_direction, int& bonus)
{
  if(enter_from_direction=="l")
  {
    slipping_to_ = "r";
  }
  else if(enter_from_direction=="r")
  {
    slipping_to_ = "l";
  }
  else if(enter_from_direction=="u")
  {
    slipping_to_ = "d";
  }
  else if(enter_from_direction=="d")
  {
    slipping_to_ = "u";
  }
  else
  {
    slipping_to_ = "invalid";
  }
  return 1; // we are on ice now!
}

bool Ice::isTurnOver(std::string &leaveThisFieldTo)
{
  leaveThisFieldTo = slipping_to_;
  return false;
}