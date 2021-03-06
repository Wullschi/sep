//------------------------------------------------------------------------------
// Bonus.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#ifndef BONUS_H_INCLUDED
#define BONUS_H_INCLUDED


#include "Field.h"

using std::string;

//------------------------------------------------------------------------------
// Class representing a Bonus field.
// The Bonus class also includes a negative bonus, which means it includes the
// Quicksand field.
//
class Bonus : public Field
{
  private:
    
    int bonus_count_;
    string bonus_letter_;
    
    //--------------------------------------------------------------------------
    // Private standard constructor
    //
    Bonus();
    
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    Bonus(const Bonus&);
    
  public:
    
    //--------------------------------------------------------------------------
    // Constant for the first letter indicating a Bonus field
    //
    static const char SYMBOL_ = 'a';
    //--------------------------------------------------------------------------
    // Constant for the last letter indicating a Quicksand field
    //
    static const char SYMBOL2_ = 'j';
    //--------------------------------------------------------------------------
    // Constant for the first letter indicating a Quicksand field
    //
    static const char SYMBOL_FIRST_QUICKSAND_ = 'f';
    
    //--------------------------------------------------------------------------
    // Resets the bonus value of a field in case of a invalid fastmove during
    // which a b fieonus field was transformed. 
    //
    // @param direction the direction in which the player has to leave the
    //        field if the turn is not over
    //
    // @return bool returns if turn is over or not
    //
    void reset();
    
    //--------------------------------------------------------------------------
    // This is the Costructor of Field class which is the base class for all
    // fields.
    //
    // @param x x-coordinate of the position of this field on the board
    // @param y y-coordinate of the position of this field on the board
    //        (coordinate origin is in the top left corner of the board)
    // @param symbol_letter the symbol of the one way field (a-j)
    //
    Bonus(int x, int y,  string symbol_letter);
    
    //--------------------------------------------------------------------------
    // Destructor
  
    ~Bonus() throw();
  
    //--------------------------------------------------------------------------
    // Getter: Gets the symbol of the field.
    //
    // @param purpose specifies if the symbol is used for saving a file or
    //        if it is used for the current game. In case of the bonus field
    //        the symbol for saving and playing can differ since a bonus field
    //        turns into a path after the player has entered. For saving, the
    //        original bonus field has to be used.
    //
    // @return the symbol of the field
  
    string getFieldSymbol(FieldSymbolPurpose purpose) const;
  
    //--------------------------------------------------------------------------
    // Performs any necessary action when a player enters a bonus field.
    // Informs of the bonus or minus points when entering the field.
    //
    // @param enter_from_direction the direction from which the player enter
    //        in the fastmove notation
    // @param bonus the bonus or minus points which are applied after
    //        entering the field.
    //
    // @return int 1 for entered ice field, 0 for entered any other field
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
