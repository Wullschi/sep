//------------------------------------------------------------------------------
// Start.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors:
// Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------

#include "Start.h"

//------------------------------------------------------------------------------
Start::Start(int x, int y) : Field(x, y)
{
  field_symbol_ = "o";
}



//------------------------------------------------------------------------------
Start::~Start()
{
}



//------------------------------------------------------------------------------
int Start::enter(std::string enter_from_direction, int& bonus)
{
  return 0;
}



//------------------------------------------------------------------------------
bool Start::isTurnOver(std::string &direction)
{
  return true;
}