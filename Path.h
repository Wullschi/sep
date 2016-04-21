//------------------------------------------------------------------------------
// path.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------
//

#ifndef PATH_H_INCLUDED
#define PATH_H_INCLUDED
#include "Field.h" //can't forward declare a the class from which this class inherits

class Path: public Field
{
  private:
    //--------------------------------------------------------------------------
    // Private standard constructor
  
    Path();
  
    //--------------------------------------------------------------------------
    // Private copy constructor
  
    Path(const Path&);
  
  public:
    Path(int x, int y);
    ~Path();
    int enter(std::string enter_from_direction, int& bonus);
    bool isTurnOver(std::string &direction);
};

#endif