//------------------------------------------------------------------------------
// Finish.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#include "Finish.h"

using std::string;

//------------------------------------------------------------------------------
Finish::Finish(int x, int y) : Field(x, y)
{
  field_symbol_ = SYMBOL_;
  can_leave_to_ = "lrud";
}

//------------------------------------------------------------------------------
Finish::~Finish() throw()
{
}


//------------------------------------------------------------------------------
int Finish::enter(string enter_from_direction, int& bonus)
{
  return 0;
}



//------------------------------------------------------------------------------
bool Finish::isTurnOver(string &direction) const
{
  return true;
}
