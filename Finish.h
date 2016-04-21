//------------------------------------------------------------------------------
// finish.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------
//

#ifndef FINISH_H_INCLUDED
#define FINISH_H_INCLUDED
#include "Field.h"

class Finish: public Field
{
  private:
    //--------------------------------------------------------------------------
    // Private standard constructor
  
    Finish();
  
    //--------------------------------------------------------------------------
    // Private copy constructor
  
    Finish(const Finish&);
  
  public:
    Finish(int x, int y);
    ~Finish();
    
    int enter(std::string enter_from_direction, int& bonus);
    bool isTurnOver(std::string &direction);
};

#endif
