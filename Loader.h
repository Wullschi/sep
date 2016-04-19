//
//  load.h
//  sep_basis
//
//  Created by Stefan Maier on 05.04.16.
//  Copyright (c) 2016 Stefan Maier. All rights reserved.
//


#ifndef LOADER_HPP
#define LOADER_HPP


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>


#include "Filehandler.h"


class Field;
class Bonus;
class Teleport;
class Ice;
class Wall;
class Path;
class Oneway;
class Start;
class Finish;
class Game;
class Field;
class Coordinates;
class Loader
{
  
private:
  std::vector< std::vector< Field* > > loaded_board_;
  
public:
  Loader();
  ~Loader();
  
  int load(Game*& game, const std::string filename);
  
  
};

#endif
