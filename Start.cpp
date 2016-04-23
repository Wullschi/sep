//------------------------------------------------------------------------------
// Start.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors:
// Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------

#include "Start.h"


const char Start::SYMBOL_ = 'o';


//------------------------------------------------------------------------------
Start::Start(int x, int y) : Field(x, y)
{
  field_symbol_ = SYMBOL_;
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