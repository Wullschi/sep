//------------------------------------------------------------------------------
// start.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors:
// Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------
//

#ifndef START_H_INCLUDED
#define START_H_INCLUDED
#include "Field.h"

class Start: public Field
{
  private:
    //--------------------------------------------------------------------------
    // Private standard constructor
  
    Start();
  
    //--------------------------------------------------------------------------
    // Private copy constructor
  
    Start(const Start&);
  
  public:
    //--------------------------------------------------------------------------
    // This is the Costructor of Field class which is the base class for all
    // fields.
    //
    // @param x x-coordinate of the position of this field on the board
    // @param y y-coordinate of the position of this field on the board
    //        (coordinate origin is in the top left corner of the board)
  
    Start(int x, int y);

    //--------------------------------------------------------------------------
    // Destructor
  
    ~Start();
  
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
  
    int enter(std::string enter_from_direction, int& bonus);
  
    //--------------------------------------------------------------------------
    // Determines if the turn is over after entering this field. And returns
    // The direction in which to go if the turn isn't over.
    //
    // @param direction the direction in which the player has to leave the
    //        field if the turn is not over
    //
    // @return bool returns if turn is over or not

    bool isTurnOver(std::string &direction);
};

#endif
