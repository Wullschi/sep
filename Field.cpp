//------------------------------------------------------------------------------
// Field.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#include "Field.h"
#include "Coordinates.h"
using std::string;


//------------------------------------------------------------------------------
Field::Field(int x, int y) : x_var_(x), y_var_(y){
  can_enter_from_ = "lrud";
  can_leave_to_ = "lrud";
}

//------------------------------------------------------------------------------
Field::~Field() throw()
{
}


//------------------------------------------------------------------------------
string Field::getFieldSymbol(FieldSymbolPurpose purpose) const
{
  return field_symbol_;
}



//------------------------------------------------------------------------------
string Field::calculateEnteringDirection(Coordinates* coming_from) const
{
  if ((x_var_ - coming_from->getX() == 1)
      && (y_var_ - coming_from->getY() == 0))
  {
    return "l";
  }
  else if ((x_var_ - coming_from->getX() == -1)
      && (y_var_ - coming_from->getY() == 0))
  {
    return "r";
  }
  
  if ((y_var_ - coming_from->getY() == 1)
      && (x_var_ - coming_from->getX() == 0))
  {
    return "u";
  }
  else if ((y_var_ - coming_from->getY() == -1)
      && (x_var_ - coming_from->getX() == 0))
  {
    return "d";
  }
  
  return "invalidTurn";
}



//------------------------------------------------------------------------------
string Field::calculateLeavingDirection(Coordinates* leaving_to) const
{
  if ((x_var_ - leaving_to->getX() == 1)
      && (y_var_ - leaving_to->getY() == 0))
  {
    return "l";
  }
  else if ((x_var_ - leaving_to->getX() == -1)
      && (y_var_ - leaving_to->getY() == 0))
  {
    return "r";
  }
  
  if ((y_var_ - leaving_to->getY() == 1)
      && (x_var_ - leaving_to->getX() == 0))
  {
    return "u";
  }
  else if ((y_var_ - leaving_to->getY() == -1)
      && (x_var_ - leaving_to->getX() == 0))
  {
    return "d";
  }
  
  return "invalidTurn";
}



//------------------------------------------------------------------------------
bool Field::isAbleToEnter(Coordinates* coming_from, string &direction) const
{
  bool can_enter;
  direction = calculateEnteringDirection(coming_from);
  
  if (can_enter_from_.find(direction) != string::npos)
  {
    can_enter = true;
  }
  else
  {
    can_enter = false;
  }
  return can_enter;
}



//------------------------------------------------------------------------------
bool Field::isAbleToLeave(Coordinates* leaving_to) const
{
  bool canLeave;
  string direction = calculateLeavingDirection(leaving_to);
  
  if (can_leave_to_.find(direction) != string::npos)
  {
    canLeave = true;
  }
  else
  {
    canLeave = false;
  }
  
  return canLeave;
}



//------------------------------------------------------------------------------
int Field::enter(string enter_from_direction, int& bonus)
{
  return 0;
}



//------------------------------------------------------------------------------
bool Field::isTurnOver(string &direction) const
{
  return true;
}



//------------------------------------------------------------------------------
void Field::reset()
{
}
