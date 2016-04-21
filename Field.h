//------------------------------------------------------------------------------
// field.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------
//

#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED
#include <string> //typedefs can not be forward declared
#include <iostream>
class Coordinates;

using std::string;

class Field
{
  private:
  
  //--------------------------------------------------------------------------
  // Private standard constructor
  
  Field();
  
  //--------------------------------------------------------------------------
  // Private copy constructor
  
  Field(const Field&);
  
  protected:
    int x_var_;
    int y_var_;
    std::string can_enter_from_;
    std::string can_leave_to_;
    std::string field_symbol_;

  public:
    Field(int x, int y);
    virtual ~Field();

    string calculateEnteringDirection(Coordinates* coming_from);
    string calculateLeavingDirection(Coordinates* leaving_to);

    bool isAbleToEnter(Coordinates* coming_from, string &direction);
    bool isAbleToLeave(Coordinates* leaving_to);

    virtual int enter(string enter_from_direction, int& bonus);

    virtual bool isTurnOver(string &direction) = 0;

    string getFieldSymbol();
};

#endif