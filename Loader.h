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
using std::string;

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
    vector<vector< Field* > >* loaded_board_;
    
    //--------------------------------------------------------------------------
    // Private copy constructor
    //
    Loader(const Loader& original);
  
    //--------------------------------------------------------------------------
    // Private assignment operator
    //
    Loader& operator=(const Loader& original);
  
    //--------------------------------------------------------------------------
    // Checks if the fastmove string and maximum turns string contain only
    // valid characters.
    //
    // @param cur_file the input filestream that reads the file
    // @param fastmove_string the string in which a valid fastmove string is
    //        saved
    // @param total_turns the variable where a valid number of turns is saved
    //
    // @return Command::Status returns if loaded lines are valid
    //
    Command::Status checkFastmoveAndMaxTurns(ifstream& cur_file,
        string& fastmove_string, unsigned int& total_turns);
  
    //--------------------------------------------------------------------------
    // Checks if the fastmove string and maximum turns string are contain only
    // valid characters.
    //
    // @param cur_file the input filestream that reads the file
    // @param start_point the coordinates where the 
    //        saved
    // @param total_turns the variable where a valid number of turns is saved
    //
    // @return Command::Status returns if the loaded board is valid
    //
    Command::Status readBoardAndCheckValidity(ifstream& cur_file,
        Coordinates*& start_point);
  
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
    // Checks the validity of a field symbol.
    //
    // @param symbol the symbol that is checked for its validity
    //
    // @return Command::Status returns if the symbol is valid or not
    //
    Command::Status checkSymbolValidity(char symbol);
  
    //--------------------------------------------------------------------------
    // Checks the validity of a field symbol.
    //
    // @param symbol the symbol of the field that is added to the row
    // @param row a vector that represents the row
    // @param found_start indicates if a start field has already been found
    // @param found_end indicates if a finish field has already been found
    // @param teleport_list a vector to keep track of all found teleport fields
    // @param start_point the coordinates of the start field are saved here
    // @param x the x coordinate of the symbol that is added to the row
    // @param y the y coordinate of the symbol that is added to the row
    //
    // @return Command::Status returns if the field was successfully added to
    //         the row
    //
    Command::Status addFieldsToRow(char symbol, vector<Field*>& row,
        bool& found_start, bool& found_end, vector<char>& teleport_list,
        Coordinates*& start_point, int x, int y);
  
    //--------------------------------------------------------------------------
    // Deletes the board and the start coordinates in case of an invalid file.
    //
    // @param start_point the start coordinates that must be deleted
    //
    void deleteBoard(Coordinates* start_point);
  
    //--------------------------------------------------------------------------
    // Deletes the board and the start coordinates in case of an invalid file.
    //
    // @param row the row vector that should be deleted
    //
  
    void deleteVector(vector<Field*>& row);
  
  public:
    
    //--------------------------------------------------------------------------
    // This is the Constructor of the Loader class
    //
    // @param filename The name of the file which should be loaded
    //
    Loader(const string filename);
  
    //--------------------------------------------------------------------------
    // Destructor
    //
    ~Loader() throw();
  
    //--------------------------------------------------------------------------
    // This method loads a file and initializes a game object.
    //
    // @param game the game object which contains the loaded board after loading
    //         is complete
    //
    // @return Constant of type Status (defined in Class Command)
    //         representing the success of the action
    //
    Command::Status load(Game*& game);
    
};


#endif
