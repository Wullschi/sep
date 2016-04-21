//------------------------------------------------------------------------------
// teleport.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------
//

#include "Teleport.h"

/****************************************************************************
 *                      Constructor und Destructor                          *
 ****************************************************************************/

Teleport::Teleport(int x, int y, std::string symbol_letter) : Field(x, y)
{
  field_symbol_ = symbol_letter;
}

Teleport::~Teleport()
{
  //std::cout << "Teleport x: " << x_var_ << "   y:  " << y_var_ << " has been deleted" <<std::endl;
}

/****************************************************************************
 *                          Restliche Funktionen                            *
 ****************************************************************************/

int Teleport::enter(std::string enter_from_direction, int& bonus)
{
  return 0;
}

bool Teleport::isTurnOver(std::string &direction)
{
  direction = field_symbol_;
  return false;
}