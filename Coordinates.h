//
//  Coordinates.hpp
//  SEP Basisbeispiel
//
//  Created by Hildebrand on 17.04.16.
//  Copyright © 2016 Benjamin. All rights reserved.
//

#ifndef COORDINATES_H_INCLUDED
#define COORDINATES_H_INCLUDED

class Coordinates
{
  private:
    int x_;
    int y_;
//--------------------------------------------------------------------------------------------
  public:
    Coordinates(const int x, const int y);
    Coordinates(const Coordinates& model);
    virtual ~Coordinates();
    void setX(int x);
    void setY(int y);
    void changeXBy(int increase_value);
    void changeYBy(int increase_value);
    void setXY(int x, int y);
    int getX() const;
    int getY() const;
};


#endif
