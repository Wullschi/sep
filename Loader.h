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
#include <fstream>
using std::vector;
using std::ifstream;

class Field;
class Game;
class Coordinates;

class Loader : public Filehandler
{
  
  private:
    std::vector< std::vector< Field* > > loaded_board_;
    //--------------------------------------------------------------------------
    // Private methods
    bool checkStartAndFinish(bool start, bool finish);
    bool checkShape();
    bool checkWall();
    bool checkTeleport(vector<char>* teleport_list);
    bool readOneRow(ifstream& cur_file, vector<char>& teleport_list,
    bool& found_start, bool& found_end, int row_count,
        Coordinates*& start_point);
    void deleteBoard(Coordinates* start_point);

  
  public:
    Loader(const std::string filename);
    ~Loader();
    
    int load(Game*& game);
    
    
};

#endif
