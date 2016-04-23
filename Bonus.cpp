//------------------------------------------------------------------------------
// Bonus.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors:
// Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------

#include "Bonus.h"


const char Bonus::SYMBOL_ = 'a';
const char Bonus::SYMBOL2_ = 'j';


//------------------------------------------------------------------------------
Bonus::Bonus(int x, int y, std::string symbol_letter) : Field(x, y)
{
  field_symbol_ = symbol_letter;
  
  if (((int)symbol_letter[0] >= 97) && ((int)symbol_letter[0] <= 101))
  {
    bonus_count_ = ((int)symbol_letter[0]) - 96;
  }
  else if (((int)symbol_letter[0] >= 102) && ((int)symbol_letter[0] <= 106))
  {
    bonus_count_ = -(((int)symbol_letter[0]) - 101);
  }
}



//------------------------------------------------------------------------------
Bonus::~Bonus()
{
}



//------------------------------------------------------------------------------
int Bonus::enter(std::string enter_from_direction, int& bonus)
{
  bonus = bonus + bonus_count_;
  return 0;
}



//------------------------------------------------------------------------------
bool Bonus::isTurnOver(std::string &direction)
{
  return true;
}
