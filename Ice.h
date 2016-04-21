//------------------------------------------------------------------------------
// ice.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------
//


#ifndef ICE_H_INCLUDED
#define ICE_H_INCLUDED
#include "Field.h"

class Ice: public Field
{
  private:
    std::string slipping_to_;
  
    //--------------------------------------------------------------------------
    // Private standard constructor
  
    Ice();
  
    //--------------------------------------------------------------------------
    // Private copy constructor
  
    Ice(const Ice&);
  
  public:
    Ice(int x, int y);
    ~Ice();
    
    int enter(std::string enter_from_direction, int& bonus);
    bool isTurnOver(std::string &direction);
    
};
#endif
