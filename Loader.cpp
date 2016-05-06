//------------------------------------------------------------------------------
// Loader.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors: Benjamin Wullschleger 0773092
// Stefan Maier 1014203
// Christopher Kopel 0730613
//------------------------------------------------------------------------------
//


#include "Loader.h"
#include "Coordinates.h"
#include "Bonus.h"
#include "Teleport.h"
#include "Ice.h"
#include "Wall.h"
#include "Path.h"
#include "OneWay.h"
#include "Start.h"
#include "Finish.h"
#include "Game.h"
#include "Fastmove.h"

using std::vector;
using std::string;
using std::ifstream;
using std::string;


//------------------------------------------------------------------------------
Loader::Loader(const string filename) :
Filehandler(filename), loaded_board_(0)
{
}




//------------------------------------------------------------------------------
Loader::~Loader() throw()
{
}




//------------------------------------------------------------------------------
Command::Status Loader::load(Game*& game)
{
  const char* LOADFILE = filename_.c_str();
  Coordinates* start_point = 0;
  ifstream cur_file;
  string fastmove_string = "";
  unsigned int total_turns = 0;
  
  
  // Check if the requested file can be opened
  cur_file.open(LOADFILE);
  if (!cur_file.is_open())
  {
    return Command::FILE_NOT_OPENED_;
  }
  
  
  // Check if first two lines only contain valid characters (fastmove and turns)
  Command::Status first_two_lines_validity =
      checkFastmoveAndMaxTurns(cur_file, fastmove_string, total_turns);
  if (first_two_lines_validity == Command::INVALID_FILE_)
  {
    return Command::INVALID_FILE_;
  }
  
  
  // try to allocate a new board for the fields we are about to load
  try
  {
    loaded_board_ = new vector<vector< Field* > >;
  }
  catch (std::bad_alloc& exception)
  {
    deleteBoard(start_point);
    return Command::OUT_OF_MEMORY_;
  }
  
  
  // read the board and check if it is valid
  Command::Status board_validity =
      readBoardAndCheckValidity(cur_file, start_point);
  if ((board_validity == Command::INVALID_FILE_) ||
      (board_validity == Command::OUT_OF_MEMORY_))
  {
    return board_validity;
  }
  
  
  // try to instantiate new game object with loaded board
  try
  {
    game = new Game(loaded_board_, "", total_turns, start_point);
  }
  catch (std::bad_alloc& exception)
  {
    deleteBoard(start_point);
    return Command::OUT_OF_MEMORY_;
  }
  
  
  // Check if loaded fastmove string can be executed correctly
  if (fastmove_string != "")
  {
    Command::Status fastmove_status = game->fastMove(fastmove_string);
    if (fastmove_status == Command::INVALID_MOVE_)
    {
      delete game;
      return Command::INVALID_PATH_;
    }
    return fastmove_status;
  }
  
  return Command::OK_;
}




//------------------------------------------------------------------------------
Command::Status Loader::checkFastmoveAndMaxTurns(ifstream& cur_file,
    string& fastmove_string, unsigned int& total_turns)
{
  string total_turns_string = "";
  
  // read fastmove string and check if it is valid
  getline(cur_file, fastmove_string);
  if ( (fastmove_string != "") &&
      (fastmove_string.find_first_not_of(Fastmove::VALID_PARAMETERS_)
       != string::npos) )
  {
    return Command::INVALID_FILE_;
  }
  
  // read max amount of turns and check if it is a valid number
  getline(cur_file, total_turns_string);
  if ( (total_turns_string.find_first_not_of("0123456789")!=string::npos)
      || (total_turns_string == "") )
  {
    return Command::INVALID_FILE_;
  }
  
  std::istringstream total_turns_stream;
  total_turns_stream.str(total_turns_string);
  total_turns_stream >> total_turns;
  
  return Command::OK_;
}




//------------------------------------------------------------------------------
Command::Status Loader::readBoardAndCheckValidity(ifstream& cur_file,
    Coordinates*& start_point)
{
  bool found_start = false;
  bool found_end = false;
  int row_count = 0;
  vector<char> teleport_list;
  
  while (!cur_file.eof())
  {
    if (cur_file.eof())
    {
      break;
    }
    
    Command::Status correct_row;
    try
    {
      correct_row = readOneRow(cur_file, teleport_list,
        found_start, found_end, row_count, start_point);
    }
    catch (std::bad_alloc& exception)
    {
      cur_file.close();
      deleteBoard(start_point);
      return Command::OUT_OF_MEMORY_;
    }
    
    
    if (correct_row == Command::INVALID_FILE_)
    {
      cur_file.close();
      deleteBoard(start_point);
      return Command::INVALID_FILE_;
    }
    
    row_count = row_count + 1;
  }
  cur_file.close();
  
  
  //a valid board has at least three rows (first and last rows are walls)
  //and at least another row which contains the start and finish fields.
  if (loaded_board_->size() < 3)
  {
    deleteBoard(start_point);
    return Command::INVALID_FILE_;
  }
  
  //check board validity
  Command::Status shape = checkShape();
  Command::Status start_and_finish =
  checkStartAndFinish(found_start, found_end);
  Command::Status wall = checkWall();
  Command::Status teleport = checkTeleport(&teleport_list);
  
  // if any error has been detected, stop loading
  if ((start_and_finish == Command::INVALID_FILE_) ||
      (shape == Command::INVALID_FILE_) || (wall == Command::INVALID_FILE_)
      || (teleport == Command::INVALID_FILE_))
  {
    deleteBoard(start_point);
    return Command::INVALID_FILE_;
  }
  
  return Command::OK_;
}




//------------------------------------------------------------------------------
Command::Status Loader::checkStartAndFinish(bool start, bool finish)
{
  if ((start == true) && (finish == true))
  {
    return Command::OK_;
  }
  else
  {
    // Start and/or End tile don't exist
    return Command::INVALID_FILE_;
  }
}




//------------------------------------------------------------------------------
Command::Status Loader::checkShape()
{
  unsigned long int field_height = loaded_board_->size();
  unsigned long int field_length = loaded_board_->at(0).size();
  for (unsigned int i = 0; i < field_height; i++)
  {
    unsigned long int row_length = loaded_board_->at(i).size();
    if (row_length != field_length)
    {
      return Command::INVALID_FILE_;
    }
  }
  return Command::OK_;
}




//------------------------------------------------------------------------------
Command::Status Loader::checkWall()
{
  vector<Field*> Row;
  unsigned long int field_height = loaded_board_->size();
  unsigned long int field_length = loaded_board_->at(0).size();
  
  /*Check if all fields in first line are walls*/
  
  for (unsigned int k = 0; k < field_length; k++)
  {
    string field_symbol = loaded_board_->at(0).at(k)->
    getFieldSymbol(Field::FOR_GAME);
    if (field_symbol != "#")
    {
      return Command::INVALID_FILE_;
    }
  }
  
  /*Check if all fields at left and right side are walls*/
  for (unsigned int k = 1; k < field_height-1; k++)
  {
    Row = loaded_board_->at(k);
    string field_symbol = loaded_board_->at(k).front()->
    getFieldSymbol(Field::FOR_GAME);
    if(field_symbol != "#")
    {
      return Command::INVALID_FILE_;
    }
    field_symbol = loaded_board_->at(k).back()->
    getFieldSymbol(Field::FOR_GAME);
    if(field_symbol != "#")
    {
      return Command::INVALID_FILE_;
    }
  }
  
  /*Check if all fields in last line are walls*/
  unsigned long int last_row_index = field_height-1;
  field_length = loaded_board_->at(last_row_index).size();
  for (unsigned int k = 0; k < field_length; k++)
  {
    string field_symbol =
    loaded_board_->at(last_row_index).at(k)->getFieldSymbol(Field::FOR_GAME);
    if (field_symbol != "#")
    {
      return Command::INVALID_FILE_;
    }
  }
  
  return Command::OK_;
}




//------------------------------------------------------------------------------
Command::Status Loader::checkTeleport(vector<char>* teleport_list)
{
  /*Check for valid Teleporter*/
  int teleport_amount;
  for(int asci = 65; asci <= 90; asci++)
  {
    teleport_amount = 0;
    for (unsigned int index = 0; index < teleport_list->size(); index++)
    {
      if (teleport_list->at(index) == asci)
      {
        teleport_amount++;
      }
    }
    
    // if 0 or 2 teleport fields for every letter exist, teleporters are valid
    if(!((teleport_amount == 0) || (teleport_amount == 2)))
    {
      return Command::INVALID_FILE_;
    }
  }
  return Command::OK_;
}




//------------------------------------------------------------------------------
Command::Status Loader::readOneRow(ifstream& cur_file,
    vector<char>& teleport_list, bool& found_start, bool& found_end,
    int row_count, Coordinates*& start_point)
{
  int y = row_count;
  vector<Field*> row;
  string row_string = "";
  unsigned long int nr_of_fields;
  
  getline(cur_file, row_string);
  nr_of_fields = row_string.size();
  
  
  
  // Check if we are reading the last line break
  // that ends the maze
  if ((cur_file.eof()) && (nr_of_fields == 0))
  {
    return Command::OK_;
  }
  // If we don't read any input in a row and we haven't
  // reached the end of a file, thats a fault
  else if((!cur_file.eof()) && (nr_of_fields == 0))
  {
    return Command::INVALID_FILE_;
  }
  // If we read input and reach the EOF, thats a fault
  // because there must be a line break befre EOF.
  else if((cur_file.eof()) && (nr_of_fields != 0))
  {
    return Command::INVALID_FILE_;
  }
  
  
  // now we can start reading the symbols in this row
  for (unsigned int x = 0; x < nr_of_fields; x++)
  {
    char symbol = row_string[x];
    
    // Check if the symbol is a valid field symbol or not
    Command::Status symbol_validity = checkSymbolValidity(symbol);
    if (symbol_validity == Command::INVALID_FILE_)
    {
      return Command::INVALID_FILE_;
    }
    
    
    try
    {
      // add the symbol to the row and check if it has been added successfully
      Command::Status added_to_row = addFieldsToRow(symbol, row, found_start,
          found_end, teleport_list, start_point, x, y);
      if (added_to_row == Command::INVALID_FILE_)
      {
        return Command::INVALID_FILE_;
      }
      
    }
    catch(std::bad_alloc& exception)
    {
      deleteVector(row);
      throw std::bad_alloc();
    }
    
  }
  
  try
  {
    loaded_board_->push_back(row);
  }
  catch(std::bad_alloc& exception)
  {
    deleteVector(row);
    throw std::bad_alloc();
  }
  
  return Command::OK_;
}




//------------------------------------------------------------------------------
Command::Status Loader::checkSymbolValidity(char symbol)
{
  if ((symbol == Path::SYMBOL_) || (symbol == Wall::SYMBOL_))
  {
    return Command::OK_;
  }
  else if ((symbol == Start::SYMBOL_) || (symbol == Finish::SYMBOL_))
  {
    return Command::OK_;
  }
  else if (symbol == Ice::SYMBOL_)
  {
    return Command::OK_;
  }
  else if ((symbol >= Teleport::SYMBOL_ ) && (symbol <= Teleport::SYMBOL2_))
  {
    return Command::OK_;
  }
  else if ((symbol == OneWay::SYMBOL_LEFT_) || (symbol == OneWay::SYMBOL_RIGHT_)
      || (symbol == OneWay::SYMBOL_UP_) || (symbol == OneWay::SYMBOL_DOWN_))
  {
    return Command::OK_;
  }
  else if ( (symbol >= Bonus::SYMBOL_) && (symbol <= Bonus::SYMBOL2_) )
  {
    return Command::OK_;
  }
  else
  {
    return Command::INVALID_FILE_;
  }
}




//------------------------------------------------------------------------------
Command::Status Loader::addFieldsToRow(char symbol, vector<Field*>& row,
    bool& found_start, bool& found_end, vector<char>& teleport_list,
    Coordinates*& start_point, int x, int y)
{
  if (symbol == Wall::SYMBOL_)
  {
    row.push_back(new Wall(x, y));
  }
  else if (symbol == Path::SYMBOL_)
  {
    row.push_back(new Path(x,y));
  }
  else if ((symbol == Start::SYMBOL_) && (found_start == false))
  {
    row.push_back(new Start(x,y));
    start_point = new Coordinates(x,y);
    found_start = true;
  }
  else if ((symbol == Start::SYMBOL_) && (found_start == true))
  {
    return Command::INVALID_FILE_;
  }
  else if (symbol == Ice::SYMBOL_)
  {
    row.push_back(new Ice(x,y));
  }
  else if ((symbol == Finish::SYMBOL_) && (found_end == false))
  {
    row.push_back(new Finish(x,y));
    found_end = true;
  }
  else if ((symbol == Finish::SYMBOL_) && (found_end == true))
  {
    return Command::INVALID_FILE_;
  }
  else if ((symbol >= Teleport::SYMBOL_ ) && (symbol <= Teleport::SYMBOL2_))
  {
    string str;
    str.push_back(symbol);
    row.push_back(new Teleport(x, y, str));
    teleport_list.push_back(symbol);
    str.clear();
  }
  else if ((symbol == OneWay::SYMBOL_LEFT_) || (symbol == OneWay::SYMBOL_RIGHT_)
      || (symbol == OneWay::SYMBOL_UP_) || (symbol == OneWay::SYMBOL_DOWN_))
  {
    string str;
    str.push_back(symbol);
    row.push_back(new OneWay(x,y,str));
    str.clear();
  }
  else if ( (symbol >= Bonus::SYMBOL_) && (symbol <= Bonus::SYMBOL2_) )
  {
    string str;
    str.push_back(symbol);
    row.push_back(new Bonus(x, y, str));
    str.clear();
  }
  return Command::OK_;
}




//------------------------------------------------------------------------------
void Loader::deleteBoard(Coordinates* start_point)
{
  for (unsigned int y = 0; y < loaded_board_->size(); ++y)
  {
    for (unsigned int x = 0; x < loaded_board_->at(y).size(); ++x)
    {
      delete loaded_board_->at(y).at(x);
      loaded_board_->at(y).at(x) = 0;
    }
  }
  loaded_board_->clear();
  delete start_point;
  start_point = 0;
  delete loaded_board_;
  loaded_board_ = 0;
}




//------------------------------------------------------------------------------
void Loader::deleteVector(vector<Field*>& row)
{
  for (unsigned int i = 0; i < row.size(); i++)
  {
    delete row.at(i);
  }
}
