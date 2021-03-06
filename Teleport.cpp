//------------------------------------------------------------------------------
// Teleport.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#include "Teleport.h"

using std::string;

//------------------------------------------------------------------------------
Teleport::Teleport(int x, int y, string symbol_letter) : Field(x, y)
{
  field_symbol_ = symbol_letter;
}

//------------------------------------------------------------------------------
Teleport::~Teleport() throw()
{
}


//------------------------------------------------------------------------------
int Teleport::enter(string enter_from_direction, int& bonus)
{
  return 0;
}



//------------------------------------------------------------------------------
bool Teleport::isTurnOver(string &portal_letter) const
{
  portal_letter = field_symbol_;
  return false;
}
