//------------------------------------------------------------------------------
// oneway.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------
//

#include "Oneway.h"

/****************************************************************************
 *                      Constructor und Destructor                          *
 ****************************************************************************/

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

OneWay::~OneWay( )
{
  std::cout << "Oneway x: " << x_var_ << "   y:  " << y_var_ << " has been deleted" <<std::endl;
}


/****************************************************************************
 *                          Restliche Funktionen                            *
 ****************************************************************************/

int OneWay::enter(std::string enter_from_direction, int& bonus)
{
  return 0;
}

bool OneWay::isTurnOver(std::string &direction)
{
  return true;
}