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

//------------------------------------------------------------------------------
// Class for loading a file, checking its validity,
// and creating the board
//
class Loader : public Filehandler
{
  private:
    
    //--------------------------------------------------------------------------
    // 2-dimensional vector of pointers to fields
    // which shall contain the board to be loaded
    //
    std::vector< std::vector< Field* > >* loaded_board_;
    
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    Loader(const Loader& original);
  
    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    Loader& operator=(const Loader& original);
    
    //--------------------------------------------------------------------------
    // Checks if start and finish fields exist.
    //
    // @param start true if only one start field has been found. False otherways
    // @param finish true if only one finish field has been found.
    //        False otherways.
    //
    // @return Command::Status returns if test was successfol or maze is invalid
    //
    Command::Status checkStartAndFinish(bool start, bool finish);
  
    //--------------------------------------------------------------------------
    // Checks if the shape of the maze is rectangular.
    //
    // @return Command::Status returns if test was successfol or maze is invalid
    //
    Command::Status checkShape();
  
    //--------------------------------------------------------------------------
    // Checks if the maze is surrounded by wall.
    //
    // @return Command::Status returns if test was successfol or maze is invalid
    //
    Command::Status checkWall();
  
    //--------------------------------------------------------------------------
    // Checks if all teleport fields come in pairs.
    //
    // @param teleport_list a list of all the teleport fields in the maze
    //
    // @return Command::Status returns if test was successfol or maze is invalid
    //
    Command::Status checkTeleport(vector<char>* teleport_list);
  
    //--------------------------------------------------------------------------
    // Reads one row of the maze, creates the fields for every symbol,
    // pushes the row into the board, and makes several validity checks
    // (checks for correct EOF, refuses invalid symbols, and counts for correct
    // number of start and finish fields.
    //
    // @param cur_file the input file-stream of the file we are reading
    // @param teleport_list a reference to the vector in which found teleport
    //        fields are stored
    // @param found_start tells if a start field was previously detected
    // @param found_end tells if a finish field was previously detected
    // @param row_count the row number of the row we are about to read
    // @param start_point saves the coordinates of the start field in case a
    //        start field was found
    //
    // @return Command::Status returns if test was successfol or maze is invalid
    //
    Command::Status readOneRow(ifstream& cur_file, vector<char>& teleport_list,
    bool& found_start, bool& found_end, int row_count,
        Coordinates*& start_point);
  
    //--------------------------------------------------------------------------
    // Deletes the board and the start coordinates in case of an invalid file.
    //
    // @param start_point the start coordinates that must be deleted
    //
    void deleteBoard(Coordinates* start_point);
    
    
  public:
    
    //------------------------------------------------------------------------------
    // This is the Constructor of the Loader class
    //
    // @param filename the name of the file which should be loaded
    //
    Loader(const std::string filename);
  
    //------------------------------------------------------------------------------
    // Destructor
    //
    ~Loader() throw();
    
    Command::Status load(Game*& game);
    
};


#endif
