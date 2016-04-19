//------------------------------------------------------------------------------
// wall.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------
//

#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED
#include "Field.h"

class Wall: public Field
{
  public:
    Wall(int x, int y);
    ~Wall();
  
    int enter(std::string enter_from_direction, int& bonus);
    bool isTurnOver(std::string &direction);
};


#endif