//------------------------------------------------------------------------------
// Wall.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors:
// Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------

#include "Wall.h"


const char Wall::SYMBOL_ = '#';


//------------------------------------------------------------------------------
Wall::Wall(int x, int y) : Field(x, y)
{
  field_symbol_ = SYMBOL_;
  can_enter_from_ = "";
  can_leave_to_ = "";
}



//------------------------------------------------------------------------------
Wall::~Wall()
{
}



//------------------------------------------------------------------------------
int Wall::enter(std::string enter_from_direction, int& bonus)
{
  return 0;
}



//------------------------------------------------------------------------------
bool Wall::isTurnOver(std::string &direction)
{
  return true;
}
