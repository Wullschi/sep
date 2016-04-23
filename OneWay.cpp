//------------------------------------------------------------------------------
// OneWay.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors:
// Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------

#include "OneWay.h"



//------------------------------------------------------------------------------
OneWay::OneWay(int x, int y, std::string symbolLetter) : Field(x, y)
{
  field_symbol_ = symbolLetter;
  
  if(symbolLetter == "<")
  {
    can_leave_to_ = "l";
  }
  else if(symbolLetter == ">")
  {
    can_leave_to_="r";
  }
  else if(symbolLetter == "^")
  {
    can_leave_to_="u";
  }
  else if(symbolLetter == "v")
  {
    can_leave_to_="d";
  }
}



//------------------------------------------------------------------------------
OneWay::~OneWay( )
{
}



//------------------------------------------------------------------------------
int OneWay::enter(std::string enter_from_direction, int& bonus)
{
  return 0;
}



//------------------------------------------------------------------------------
bool OneWay::isTurnOver(std::string &direction)
{
  return true;
}
