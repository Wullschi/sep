//------------------------------------------------------------------------------
// start.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------
//

#include "Start.h"

/****************************************************************************
 *                      Constructor und Destructor                          *
 ****************************************************************************/

Start::Start(int x, int y) : Field(x, y)
{
  field_symbol_ = "o";
}

Start::~Start()
{
  std::cout << "Field x: " << x_var_ << "   y:  " << y_var_ << " has been deleted" <<std::endl;
}

/****************************************************************************
 *                          Restliche Funktionen                            *
 ****************************************************************************/
int Start::enter(std::string enter_from_direction, int& bonus)
{
  return 0;
}

bool Start::isTurnOver(std::string &direction)
{
  return true;
}