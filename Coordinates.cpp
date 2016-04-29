//------------------------------------------------------------------------------
// Coordinates.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#include "Coordinates.h"
#include <iostream>


/****************************************************************************
 *                      Constructor und Destructor                          *
 ****************************************************************************/

Coordinates::Coordinates(const int x, const int y):x_(x), y_(y)
{}

Coordinates::Coordinates(const Coordinates& original)
{
  x_ = original.getX();
  y_ = original.getY();
}

Coordinates::~Coordinates(){}

/****************************************************************************
 *                          Restliche Funktionen                            *
 ****************************************************************************/
void Coordinates::setX(int x)
{
  x_ = x;
}
void Coordinates::setY(int y)
{
  y_ = y;
}
void Coordinates::setXY(int x, int y)
{
  x_ = x;
  y_ = y;
}


int Coordinates::getX() const
{
  return x_;
}
int Coordinates::getY() const
{
  return y_;
}

void Coordinates::changeXBy(int increase_value)
{
  x_ = x_ + increase_value;
}
void Coordinates::changeYBy(int increase_value)
{
  y_ = y_ + increase_value;
}
