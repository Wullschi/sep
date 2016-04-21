//------------------------------------------------------------------------------
// finish.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------
//

#include "Finish.h"

/****************************************************************************
 *                      Constructor und Destructor                          *
 ****************************************************************************/

Finish::Finish(int x, int y) : Field(x, y)
{
  field_symbol_ = "x";
  can_leave_to_ = "lrud";
}

Finish::~Finish()
{
  //std::cout << "Finish x: " << x_var_ << "   y:  " << y_var_ << " has been deleted" <<std::endl;
}

/****************************************************************************
 *                          Restliche Funktionen                            *
 ****************************************************************************/
int Finish::enter(std::string enter_from_direction, int& bonus)
{
  return 0;
}

bool Finish::isTurnOver(std::string &direction)
{
  return true;
}