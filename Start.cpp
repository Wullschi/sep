//------------------------------------------------------------------------------
// Start.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#include "Start.h"

using std::string;

//------------------------------------------------------------------------------
Start::Start(int x, int y) : Field(x, y)
{
  field_symbol_ = SYMBOL_;
}

//------------------------------------------------------------------------------
Start::~Start() throw()
{
}

//------------------------------------------------------------------------------
int Start::enter(string enter_from_direction, int& bonus)
{
  return 0;
}



//------------------------------------------------------------------------------
bool Start::isTurnOver(string &direction) const
{
  return true;
}
