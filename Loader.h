//------------------------------------------------------------------------------
// Loader.h
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#ifndef LOADER_H_INCLUDED
#define LOADER_H_INCLUDED


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "Filehandler.h"

#include "Command.h"   // necessary to access Status constants

using std::vector;
using std::ifstream;

class Field;
class Game;
class Coordinates;
class Loader : public Filehandler
{
  private:
    
    //------------------------------------------------------------------------------
    // 2-dimensional vector of pointers to fields
    // which shall contain the board to be loaded
    //
    std::vector< std::vector< Field* > >* loaded_board_;
    
    //------------------------------------------------------------------------------
    // Private copy constructor
    //
    Loader(const Loader& original);
    //------------------------------------------------------------------------------
    // Private assignment operator
    //
    Loader& operator=(const Loader& original);
    
    //--------------------------------------------------------------------------
    // Private methods
    //
    Command::Status checkStartAndFinish(bool start, bool finish);
    Command::Status checkShape();
    Command::Status checkWall();
    Command::Status checkTeleport(vector<char>* teleport_list);
    Command::Status readOneRow(ifstream& cur_file, vector<char>& teleport_list,
    bool& found_start, bool& found_end, int row_count,
        Coordinates*& start_point);
    void deleteBoard(Coordinates* start_point);
    
    
  public:
    
    //------------------------------------------------------------------------------
    // Constructor
    //
    Loader(const std::string filename);
    //------------------------------------------------------------------------------
    // Destructor
    //
    ~Loader() throw();
    
    Command::Status load(Game*& game);
    
};


#endif
