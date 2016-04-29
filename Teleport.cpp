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


const char Teleport::SYMBOL_ = 'A';
const char Teleport::SYMBOL2_ = 'Z';


//------------------------------------------------------------------------------
Teleport::Teleport(int x, int y, std::string symbol_letter) : Field(x, y)
{
  field_symbol_ = symbol_letter;
}



//------------------------------------------------------------------------------
Teleport::~Teleport()
{
}



//------------------------------------------------------------------------------
int Teleport::enter(std::string enter_from_direction, int& bonus)
{
  return 0;
}



//------------------------------------------------------------------------------
bool Teleport::isTurnOver(std::string &portal_letter)
{
  portal_letter = field_symbol_;
  return false;
}
