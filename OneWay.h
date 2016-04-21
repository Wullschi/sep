//------------------------------------------------------------------------------
// oneway.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------
//


#ifndef ONEWAY_H_INCLUDED
#define ONEWAY_H_INCLUDED
#include "Field.h"

class OneWay: public Field
{
  private:
    //--------------------------------------------------------------------------
    // Private standard constructor
  
    OneWay();
  
    //--------------------------------------------------------------------------
    // Private copy constructor
  
    OneWay(const OneWay&);
  
    
  public:
    OneWay(int x, int y, std::string symbolLetter);
    ~OneWay();
    
    int enter(std::string enter_from_direction, int& bonus);
    bool isTurnOver(std::string &direction);
    
};
#endif
