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
    //--------------------------------------------------------------------------
    // This is the Costructor of Field class which is the base class for all
    // fields.
    //
    // @param x x-coordinate of the position of this field on the board
    // @param y x-coordinate of the position of this field on the board
    //        (coordinate origin is in the top left corner of the board)
  
    Field(int x, int y);
  
    //--------------------------------------------------------------------------
    // Destructor
  
    virtual ~Field();

    //--------------------------------------------------------------------------
    // Calculates from which direction the player wants to enter this field
    // and returns the result in the fastmove notation.
    //
    // @param coming_from the coordinates from where the player wants to enter
    //        this field
    //
    // @return string the direction the player wants to enter this field in the
    //         fastmove notation
  
    string calculateEnteringDirection(Coordinates* coming_from);

    //--------------------------------------------------------------------------
    // Calculates in which direction the player wants to leave this field
    // and returns the result in the fastmove notation.
    //
    // @param leaving_to the coordinates to which the player wants to leave
    //        this field
    //
    // @return string the direction the player wants to leave this field in the
    //         fastmove notation
  
    string calculateLeavingDirection(Coordinates* leaving_to);

    //--------------------------------------------------------------------------
    // Determines if the player can enter this field from the given
    // field/direction.
    //
    // @param coming_from the coordinates from where the player wants to enter
    //        this field
    // @param coming_from the direction from which the player wants to enter
    //        this field in the fastmove notation
    //
    // @return bool returns if the player may enter the field from the desired
    //         direction
  
    bool isAbleToEnter(Coordinates* coming_from, string &direction);
  
    //--------------------------------------------------------------------------
    // Calculates in which direction the player wants to leave this field
    // and returns the result in the fastmove notation.
    //
    // @param leaving_to the coordinates to which the player wants to leave
    //        this field
    //
    // @return bool returns if the player may leave the field in the desired
    //         direction
  
    bool isAbleToLeave(Coordinates* leaving_to);

    virtual int enter(string enter_from_direction, int& bonus);

    virtual bool isTurnOver(string &direction) = 0;

    string getFieldSymbol();
};

#endif