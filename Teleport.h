//------------------------------------------------------------------------------
// teleport.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------
//


#ifndef TELEPORT_H_INCLUDED
#define TELEPORT_H_INCLUDED
#include "Field.h"
class Teleport: public Field
{
  private:
    //--------------------------------------------------------------------------
    // Private standard constructor
  
    Teleport();
  
    //--------------------------------------------------------------------------
    // Private copy constructor
  
    Teleport(const Teleport&);
  
  public:
    Teleport(int x, int y, std::string symbol_letter);
    ~Teleport();
  
    int enter(std::string enter_from_direction, int& bonus);
    bool isTurnOver(std::string &direction);
};

#endif