//------------------------------------------------------------------------------
// Coordinates.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#ifndef COORDINATES_H_INCLUDED
#define COORDINATES_H_INCLUDED


#include <string> //typedefs can not be forward declared
#include <iostream>
class Coordinates
{
  private:
    int x_;
    int y_;

    //--------------------------------------------------------------------------
    // Private standard constructor
  
    Coordinates();

  public:
    Coordinates(const int x, const int y);
  
    //--------------------------------------------------------------------------
    // Public copy constructor
    Coordinates(const Coordinates& original);
  
    //--------------------------------------------------------------------------
    // Destructor
  
    virtual ~Coordinates();

    //--------------------------------------------------------------------------
    // Setter: Sets the x-coordinate
    //
    // @param x the coordinate which is set
  
    void setX(int x);
  
    //--------------------------------------------------------------------------
    // Setter: Sets the x-coordinate
    //
    // @param y the coordinate which is set
  
    void setY(int y);
  
    //--------------------------------------------------------------------------
    // Setter: Sets an x- and y-coordinate at the same time.
    //
    // @param x the x coordinate which is set
    // @param y the y coordinate which is set
  
    void setXY(int x, int y);

    //--------------------------------------------------------------------------
    // Getter: Gets the x-coordinate.
    //
    // @return int the returned y-coordinate

  
    int getX() const;
  
    //--------------------------------------------------------------------------
    // Getter: Gets the x-coordinate.
    //
    // @return int the returned y-coordinate

  
    int getY() const;
  
    //--------------------------------------------------------------------------
    // Adds a specified value to the coordinate
    //
    // @param increase_value the value that is added to the coordinate
  
    void changeXBy(int increase_value);
  
    //--------------------------------------------------------------------------
    // Adds a specified value to the coordinate
    //
    // @param increase_value the value that is added to the coordinate
  
    void changeYBy(int increase_value);
  
};


#endif
