//------------------------------------------------------------------------------
// Teleport.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#ifndef TELEPORT_H_INCLUDED
#define TELEPORT_H_INCLUDED


#include "Field.h"

using std::string;

//------------------------------------------------------------------------------
// Class representing a Teleport field
//
class Teleport : public Field
{
  private:
    
    //--------------------------------------------------------------------------
    // Private standard constructor
    //
    Teleport();
    
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    Teleport(const Teleport& original);
  
  public:
    
    //--------------------------------------------------------------------------
    // Constants for the first and the last letter representing this type 
    // of field on the textmode screen and in the file
    //
    static const char SYMBOL_ = 'A';
    static const char SYMBOL2_ = 'Z';
    
    //--------------------------------------------------------------------------
    // This is the Costructor of Field class which is the base class for all
    // fields.
    //
    // @param x x-coordinate of the position of this field on the board
    // @param y y-coordinate of the position of this field on the board
    //        (coordinate origin is in the top left corner of the board)
    // @param symbol_letter the symbol of the one way field (a-j)
    //
    Teleport(int x, int y, string symbol_letter);
    
    //--------------------------------------------------------------------------
    // Destructor
    //
    ~Teleport() throw();
    
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
    //
    int enter(string enter_from_direction, int& bonus);
    
    //--------------------------------------------------------------------------
    // Determines if the turn is over after entering this field. And returns
    // The direction in which to go if the turn isn't over which is a
    // portal letter A-Z in this case.
    //
    // @param portal_letter the portal letter to which the player exits the
    //        entered portal
    //
    // @return bool returns if turn is over or not
    //
    bool isTurnOver(string &portal_letter) const;
    
};


#endif
