//------------------------------------------------------------------------------
// Ice.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#ifndef ICE_H_INCLUDED
#define ICE_H_INCLUDED


#include "Field.h"

using std::string;

//------------------------------------------------------------------------------
// Class representing an Ice field
//
class Ice : public Field
{
  private:
    
    string slipping_to_;
  
    //--------------------------------------------------------------------------
    // Private standard constructor
    //
    Ice();
    
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    Ice(const Ice& original);
    
  public:
    
    //--------------------------------------------------------------------------
    // Constant for the text symbol representing this type of  field
    // on the textmode screen and in the file
    //
    static const char SYMBOL_ = '+';
    
    //--------------------------------------------------------------------------
    // This is the Costructor of Field class which is the base class for all
    // fields.
    //
    // @param x x-coordinate of the position of this field on the board
    // @param y y-coordinate of the position of this field on the board
    //        (coordinate origin is in the top left corner of the board)
    //
    Ice(int x, int y);
    
    //--------------------------------------------------------------------------
    // Destructor
    //
    ~Ice() throw();
    
    //--------------------------------------------------------------------------
    // Performs any necessary action when a player enters an ice field. This
    // method returns the direction in which the player is sliding on the ice.
    //
    // @param enter_from_direction the direction from which the player enter
    //        in the fastmove notation
    // @param bonus the bonus or minus points which might be applied after
    //        entering the field.
    //
    // @return int returns 1 which means the player entered an ice field
    //
    int enter(string enter_from_direction, int& bonus);
    
    //--------------------------------------------------------------------------
    // Determines if the turn is over after entering this field. And returns
    // The direction in which to go if the turn isn't over.
    //
    // @param direction the direction in which the player has to leave the
    //        field if the turn is not over
    //
    // @return bool returns if turn is over or not
    //
    bool isTurnOver(string &direction) const;
    
};


#endif
