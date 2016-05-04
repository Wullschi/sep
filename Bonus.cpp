//------------------------------------------------------------------------------
// Bonus.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#include "Bonus.h"

using std::string;

//------------------------------------------------------------------------------
Bonus::Bonus(int x, int y, string symbol_letter) : Field(x, y),
    bonus_letter_(symbol_letter)
{
  field_symbol_ = symbol_letter;
  reset();
}

//------------------------------------------------------------------------------
Bonus::~Bonus() throw()
{
}


//------------------------------------------------------------------------------
string Bonus::getFieldSymbol(FieldSymbolPurpose purpose) const
{
  if (purpose == FOR_SAVING)// return bonus field for saving
  {
    return bonus_letter_;
  }
  else //return bonus field which is valid during the game
  {
    return field_symbol_;
  }
}

//------------------------------------------------------------------------------
void Bonus::reset()
{
  if ( (bonus_letter_[0] >= SYMBOL_) && (bonus_letter_[0]
      < SYMBOL_FIRST_QUICKSAND_) )
  {
    bonus_count_ = bonus_letter_[0] - SYMBOL_ + 1;
  }
  else if ( (bonus_letter_[0] >= SYMBOL_FIRST_QUICKSAND_)
      && (bonus_letter_[0] <= SYMBOL2_) )
  {
    bonus_count_ = -(bonus_letter_[0] - SYMBOL_FIRST_QUICKSAND_ + 1);
  }
  field_symbol_ = bonus_letter_;
}


//------------------------------------------------------------------------------
int Bonus::enter(string enter_from_direction, int& bonus)
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
bool Bonus::isTurnOver(string &direction) const
{
  return true;
}
