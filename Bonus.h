//------------------------------------------------------------------------------
// bonus.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------
//


#ifndef BONUS_H_INCLUDED
#define BONUS_H_INCLUDED
#include "Field.h"

class Bonus: public Field
{
  private:
    int bonus_count_; //nur in Quicksand/Bonusfeld
    
  public:
    Bonus(int x, int y,  std::string symbolLetter);
    ~Bonus();
  
    int enter(std::string enter_from_direction, int& bonus);
    bool isTurnOver(std::string &direction);
};

#endif