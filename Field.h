//------------------------------------------------------------------------------
// Field.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
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
  
    enum FieldSymbolPurpose
    {
      FOR_GAME = 0,
      FOR_SAVING = 1
    };

    //--------------------------------------------------------------------------
    // This is the Costructor of Field class which is the base class for all
    // fields.
    //
    // @param x x-coordinate of the position of this field on the board
    // @param y y-coordinate of the position of this field on the board
    //        (coordinate origin is in the top left corner of the board)
  
    Field(int x, int y);
  
    //--------------------------------------------------------------------------
    // Destructor
  
    virtual ~Field() throw();
  
  
    //--------------------------------------------------------------------------
    // Getter: Gets the symbol of the field.
    //
    // @return the symbol of the field
  
    virtual string getFieldSymbol(FieldSymbolPurpose purpose);

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
    //
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
    // Calculates if the player is able to leave the field in the desired
    // direction.
    //
    // @param leaving_to the coordinates to which the player wants to leave.
    //
    //
    // @return bool returns if the player may leave the field in the desired
    //         direction
  
    bool isAbleToLeave(Coordinates* leaving_to);
  
    //--------------------------------------------------------------------------
    // Performs any necessary action when a player enters a field. This Method
    // is mainly used for the bonus/quicksand and ice fields.
    //
    // @param enter_from_direction the direction from which the player enter
    //        in the fastmove notation
    // @param bonus the bonus or minus points which might be applied after
    //        entering the field.
    //
    // @return int 1 for entered ice field, 0 for entered any other field

    virtual int enter(string enter_from_direction, int& bonus);
  
    //--------------------------------------------------------------------------
    // Determines if the turn is over after entering this field. And returns
    // The direction in which to go if the turn isn't over.
    //
    // @param direction the direction in which the player has to leave the
    //        field if the turn is not over
    //
    // @return bool returns if turn is over or not

    virtual bool isTurnOver(string &direction) = 0;
  
    //--------------------------------------------------------------------------
    // Action that has to be performed to put the field into its initial state
  
    virtual void reset();
};


#endif
