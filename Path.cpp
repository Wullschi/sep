//------------------------------------------------------------------------------
// Path.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#include "Path.h"


//------------------------------------------------------------------------------
Path::Path(int x, int y) : Field(x, y)
{
  field_symbol_ = SYMBOL_;
}

//------------------------------------------------------------------------------
Path::~Path() throw()
{
}


//------------------------------------------------------------------------------
int Path::enter(std::string enter_from_direction, int& bonus)
{
  return 0;
}



//------------------------------------------------------------------------------
bool Path::isTurnOver(std::string &direction)
{
  return true;
}
