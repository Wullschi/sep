//
//  load.h
//  sep_basis
//
//  Created by Stefan Maier on 05.04.16.
//  Copyright (c) 2016 Stefan Maier. All rights reserved.
//


#ifndef LOADER_H_INCLUDED
#define LOADER_H_INCLUDED


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>


#include "Filehandler.h"


class Field;
class Game;
class Loader : public Filehandler
{
  
  private:
    std::vector< std::vector< Field* > > loaded_board_;
    
  public:
    Loader(const std::string filename);
    ~Loader();
    
    int load(Game*& game);
    
    
};

#endif
