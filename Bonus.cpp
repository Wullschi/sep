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
  bonus_letter_ = symbol_letter;
  field_symbol_ = symbol_letter;
  reset();
}



//------------------------------------------------------------------------------
Bonus::~Bonus()
{
}

//------------------------------------------------------------------------------
void Bonus::reset()
{
  if (((int)bonus_letter_[0] >= 97) && ((int)bonus_letter_[0] <= 101))
  {
    bonus_count_ = ((int)bonus_letter_[0]) - 96;
  }
  else if (((int)bonus_letter_[0] >= 102) && ((int)bonus_letter_[0] <= 106))
  {
    bonus_count_ = -(((int)bonus_letter_[0]) - 101);
  }
  field_symbol_ = bonus_letter_;
}



//------------------------------------------------------------------------------
int Bonus::enter(std::string enter_from_direction, int& bonus)
{
  bonus = bonus + bonus_count_;
  
  if (bonus_count_ > 0)
  {
    bonus_count_ = 0;
    field_symbol_ = " ";
  }
  
  return 0;
}



//------------------------------------------------------------------------------
bool Bonus::isTurnOver(std::string &direction)
{
  return true;
}
