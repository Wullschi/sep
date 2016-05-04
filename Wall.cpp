//------------------------------------------------------------------------------
// Wall.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#include "Wall.h"

using std::string;

//------------------------------------------------------------------------------
Wall::Wall(int x, int y) : Field(x, y)
{
  field_symbol_ = SYMBOL_;
  can_enter_from_ = "";
  can_leave_to_ = "";
}

//------------------------------------------------------------------------------
Wall::~Wall() throw()
{
}


//------------------------------------------------------------------------------
int Wall::enter(string enter_from_direction, int& bonus)
{
  return 0;
}



//------------------------------------------------------------------------------
bool Wall::isTurnOver(string &direction) const
{
  return true;
}
