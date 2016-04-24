//------------------------------------------------------------------------------
// Loader.cpp
//
// Group: Group 13717, study assistant: Pascal Nasahl
//
// Authors:
// Stefan Maier 1014203
// Benjamin Wullschleger 0773092
//------------------------------------------------------------------------------



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

Loader::Loader(const std::string filename) : Filehandler(filename)
{
  loaded_board_ = new std::vector< std::vector< Field* > >;
}

Loader::~Loader()
{
}



/*Loading function*/
Command::Status Loader::load(Game*& game)
{
  const char* LOADFILE = filename_.c_str();
  Coordinates* start_point = 0;
  /*Initialisierungen*/
  std::ifstream cur_file;
  bool found_start = false;
  bool found_end = false;
  int row_count = 0;
  cur_file.open(LOADFILE);
  
  std::vector<char> teleport_list;
  std::string turns_string = "";
  std::string total_turns_string = "";
  std::string fastmove_string = "";

  unsigned int total_turns = 0;
  

  if(cur_file.is_open())
  {
    /*Reading the file*/
    std::vector<Field*> row;
    
    // read fastmove string and check if it is valid
    getline(cur_file, fastmove_string);
    if ( (fastmove_string != "") && (fastmove_string.find_first_not_of(Fastmove::VALID_COMMANDS_) != std::string::npos) )
    {
      deleteBoard(start_point);
      return Command::INVALID_FILE_;
    }
    
    // read max amount of turns and check if it is a valid number
    getline(cur_file, total_turns_string);
    if(total_turns_string.find_first_not_of("0123456789")!=std::string::npos)
    {
      deleteBoard(start_point);
      return Command::INVALID_FILE_;
    }
    
    std::istringstream total_turns_stream;
    total_turns_stream.str(total_turns_string);
    total_turns_stream >> total_turns;
    
    
    // start reading the board if fastmove string and max turns are valid
    while (!cur_file.eof())
    {
      if (cur_file.eof())
      {
        break;
      }
     
      
      Command::Status correct_row = readOneRow(cur_file, teleport_list, found_start, found_end, row_count, start_point);
      

      
      if (correct_row == Command::INVALID_FILE_)
      {
        deleteBoard(start_point);
        return Command::INVALID_FILE_;
      }
      else if (correct_row == Command::OUT_OF_MEMORY_)
      {
        deleteBoard(start_point);
        return Command::OUT_OF_MEMORY_;
      }

      row.clear();
      row_count = row_count + 1;
    }
    std::cout << "geladen\n";
    cur_file.close();
    


    //check board validity
    Command::Status start_and_finish = checkStartAndFinish(found_start, found_end);
    Command::Status shape = checkShape();
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
    
    try
    {
      game = new Game(loaded_board_, "", total_turns, start_point);
    }
    catch (std::bad_alloc& exception)
    {
      deleteBoard(start_point);
      return Command::OUT_OF_MEMORY_;
    }
    
    if (fastmove_string != "")
    {
      Command::Status fastmove_status = game->fastMove(fastmove_string);
      if (fastmove_status == Command::INVALID_MOVE_)
      {
        deleteBoard(start_point);
        return Command::INVALID_PATH_;
      }
      return fastmove_status;
    }
    
  }
  else
  {
    deleteBoard(start_point);
    return Command::FILE_NOT_OPENED_;
  }

  return Command::OK_;
}

































Command::Status Loader::checkStartAndFinish(bool start, bool finish)
{
  if ((start == true) && (finish == true))
  {
    return Command::OK_;
  }
  else
  {
    /*Start and/or End tile don't exist*/
    return Command::INVALID_FILE_;
  }
}

Command::Status Loader::checkShape()
{
  unsigned long int field_height = loaded_board_->size();
  unsigned long int field_length = loaded_board_->at(0).size();
  for(int i = 0; i < field_height; i++)
  {
    unsigned long int row_length = loaded_board_->at(i).size();
    if (row_length != field_length)
    {
      return Command::INVALID_FILE_;
    }
  }
  return Command::OK_;
}

Command::Status Loader::checkWall()
{
  std::vector<Field*> Row;
  unsigned long int field_height = loaded_board_->size();
  unsigned long int field_length = loaded_board_->at(0).size();
  
  /*Check if all fields in first line are walls*/
  for(int k = 0; k < field_length; k++)
  {
    string field_symbol = loaded_board_->at(0).at(k)->getFieldSymbol();
    if (field_symbol != "#")
    {
      return Command::INVALID_FILE_;
    }
  }
  
  /*Check if all fields at left and right side are walls*/
  for(int k = 1; k < field_height-1; k++)
  {
    Row = loaded_board_->at(k);
    string field_symbol = loaded_board_->at(k).front()->getFieldSymbol();
    if(field_symbol != "#")
    {
      return Command::INVALID_FILE_;
    }
    field_symbol = loaded_board_->at(k).back()->getFieldSymbol();
    if(field_symbol != "#")
    {
      return Command::INVALID_FILE_;
    }
  }
  
  /*Check if all fields in last line are walls*/
  for(int k = 0; k < field_length; k++)
  {
    string field_symbol = loaded_board_->at(field_height-1).at(k)->getFieldSymbol();
    if (field_symbol != "#")
    {
      return Command::INVALID_FILE_;
    }
  }
  
  return Command::OK_;
}

Command::Status Loader::checkTeleport(vector<char>* teleport_list)
{
  /*Check for valid Teleporter*/
  int teleport_amount;
  for(int asci = 65; asci <= 90; asci++)
  {
    teleport_amount = 0;
    for(int k = 0; k < teleport_list->size(); k++)
    {
      if(teleport_list->at(k) == asci)
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










Command::Status Loader::readOneRow(ifstream& cur_file, vector<char>& teleport_list,
                        bool& found_start, bool& found_end, int row_count, Coordinates*& start_point)
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
  for (int x = 0; x < nr_of_fields; x++)
  {
    bool valid_char = false;
    char symbol = row_string[x];
    
    
    try
    {
      /*Generating the Field*/
      if (symbol == Wall::SYMBOL_)
      {
        row.push_back(new Wall(x, y));
        valid_char = true;
      }
      
      if (symbol == Path::SYMBOL_)
      {
        row.push_back(new Path(x,y));
        valid_char = true;
      }
      
      if ((symbol == Start::SYMBOL_) && (found_start == false))
      {
        row.push_back(new Start(x,y));
        start_point = new Coordinates(x,y);
        valid_char = true;
        found_start = true;
      }
      
      else if ((symbol == Start::SYMBOL_) && (found_start == true))
      {
        return Command::INVALID_FILE_;
      }
      
      if (symbol == Ice::SYMBOL_)
      {
        row.push_back(new Ice(x,y));
        valid_char = true;
      }
      
      if ((symbol == Finish::SYMBOL_) && (found_end == false))
      {
        row.push_back(new Finish(x,y));
        valid_char = true;
        found_end = true;
      }
      
      
      else if ((symbol == Finish::SYMBOL_) && (found_end == true))
      {
        return Command::INVALID_FILE_;
      }
      
      if ((symbol >= Teleport::SYMBOL_ ) && (symbol <= Teleport::SYMBOL2_))
      {
        string str;
        str.push_back(symbol);
        row.push_back(new Teleport(x, y, str));
        teleport_list.push_back(symbol);
        valid_char = true;
        str.clear();
      }
      
      if ((symbol == OneWay::SYMBOL_LEFT_) || (symbol == OneWay::SYMBOL_RIGHT_) || (symbol == OneWay::SYMBOL_UP_)
          || (symbol == OneWay::SYMBOL_DOWN_))
      {
        string str;
        str.push_back(symbol);
        row.push_back(new OneWay(x,y,str));
        valid_char = true;
        str.clear();
      }
      
      if ( (symbol >= Bonus::SYMBOL_) && (symbol <= Bonus::SYMBOL2_) )
      {
        string str;
        str.push_back(symbol);
        row.push_back(new Bonus(x, y, str));
        valid_char = true;
        str.clear();
      }
      
      if(valid_char == false)
      {
        return Command::INVALID_FILE_;
      }
    }
    catch(std::bad_alloc& exception)
    {
      
      for (int i = 0; i < row.size(); i++)
      {
        delete row.at(i);
      }
      
      return Command::OUT_OF_MEMORY_;
    }
  }
  
  loaded_board_->push_back(row);
  return Command::OK_;
}






void Loader::deleteBoard(Coordinates* start_point)
{
  for (int y = 0; y < loaded_board_->size(); ++y)
  {
    for (int x = 0; x < loaded_board_->at(y).size(); ++x)
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
