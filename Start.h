//------------------------------------------------------------------------------
// start.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------
//

#ifndef START_H_INCLUDED
#define START_H_INCLUDED
#include "Field.h"

class Start: public Field
{
  public:
    Start(int x, int y);
    ~Start();
    
    int enter(std::string enter_from_direction, int& bonus);
    bool isTurnOver(std::string &direction);
};

#endif