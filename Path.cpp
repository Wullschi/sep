//------------------------------------------------------------------------------
// path.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------
//

#include "Path.h"

/****************************************************************************
 *                      Constructor und Destructor                          *
 ****************************************************************************/

Path::Path(int x, int y) : Field(x, y)
{
  field_symbol_ = " ";
}

Path::~Path()
{
  std::cout << "Path x: " << x_var_ << "   y:  " << y_var_ << " has been deleted" <<std::endl;
}

/****************************************************************************
 *                          Restliche Funktionen                            *
 ****************************************************************************/
int Path::enter(std::string enter_from_direction, int& bonus)
{
  return 0;
}

bool Path::isTurnOver(std::string &direction)
{
  return true;
}