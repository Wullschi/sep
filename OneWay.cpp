//------------------------------------------------------------------------------
// OneWay.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors:
// Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------

#include "OneWay.h"


const char OneWay::SYMBOL_LEFT_ = '<';
const char OneWay::SYMBOL_RIGHT_ = '>';
const char OneWay::SYMBOL_DOWN_ = 'v';
const char OneWay::SYMBOL_UP_ = '^';


//------------------------------------------------------------------------------
OneWay::OneWay(int x, int y, std::string symbol_letter) : Field(x, y)
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
