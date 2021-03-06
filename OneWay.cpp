//------------------------------------------------------------------------------
// OneWay.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#include "OneWay.h"

using std::string;

//------------------------------------------------------------------------------
OneWay::OneWay(int x, int y, string symbol_letter) : Field(x, y)
{
  field_symbol_ = symbol_letter;
  
  if (symbol_letter[0] == SYMBOL_LEFT_)
  {
    can_leave_to_ = "l";
  }
  else if (symbol_letter[0] == SYMBOL_RIGHT_)
  {
    can_leave_to_="r";
  }
  else if (symbol_letter[0] == SYMBOL_UP_)
  {
    can_leave_to_="u";
  }
  else if (symbol_letter[0] == SYMBOL_DOWN_)
  {
    can_leave_to_="d";
  }
}

//------------------------------------------------------------------------------
OneWay::~OneWay() throw()
{
}


//------------------------------------------------------------------------------
int OneWay::enter(string enter_from_direction, int& bonus)
{
  return 0;
}



//------------------------------------------------------------------------------
bool OneWay::isTurnOver(string &direction) const
{
  return true;
}
